import requests
import os

def fetch_leetcode_submission(problem_slug, session_cookie, csrf_token, username, output_folder="leetcode_solutions"):
    # Create output folder if it doesn't exist
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    # Common headers
    headers = {
        "Cookie": f"LEETCODE_SESSION={session_cookie}; csrftoken={csrf_token}",
        "x-csrftoken": csrf_token,
        "Referer": "https://leetcode.com/",
        "Content-Type": "application/json",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36"
    }

    # Step 1: Get recent submissions to find submission ID
    list_query = """
    query recentSubmissionList($username: String!, $limit: Int!) {
        recentSubmissionList(username: $username, limit: $limit) {
            id
            title
            titleSlug
            lang
            statusDisplay
        }
    }
    """
    
    list_payload = {
        "query": list_query,
        "variables": {"username": username, "limit": 20},
        "operationName": "recentSubmissionList"
    }

    try:
        print(f"Fetching submission list for {problem_slug}")
        list_response = requests.post("https://leetcode.com/graphql", headers=headers, json=list_payload)
        list_response.raise_for_status()
        
        # Debug: Print raw response
        response_data = list_response.json()
        print("Raw response:", response_data)
        
        # Check if data exists
        if "data" not in response_data or "recentSubmissionList" not in response_data["data"]:
            print("Error: Unexpected response structure")
            return
        
        submissions = response_data["data"]["recentSubmissionList"]
        if submissions is None:
            print("Error: No submissions found. Check username or authentication")
            return
        
        # Find accepted submission
        submission_id = None
        lang = None
        problem_title = None
        for sub in submissions:
            if sub["titleSlug"] == problem_slug and sub["statusDisplay"] == "Accepted":
                submission_id = sub["id"]
                lang = sub["lang"]
                problem_title = sub["title"]
                break
        
        if not submission_id:
            print(f"No accepted submission found for {problem_slug} in recent submissions")
            return

        # Step 2: Get submission details with code
        details_query = """
        query submissionDetails($submissionId: Int!) {
            submissionDetails(submissionId: $submissionId) {
                code
                lang {
                    name
                }
            }
        }
        """
        
        details_payload = {
            "query": details_query,
            "variables": {"submissionId": int(submission_id)},
            "operationName": "submissionDetails"
        }
        
        print(f"Fetching submission details for ID: {submission_id}")
        details_response = requests.post("https://leetcode.com/graphql", headers=headers, json=details_payload)
        details_response.raise_for_status()
        
        details = details_response.json()["data"]["submissionDetails"]
        code = details["code"]
        
        # Map language to extension
        ext_map = {
            "python": ".py",
            "python3": ".py",
            "cpp": ".cpp",
            "java": ".java",
            "javascript": ".js"
        }
        ext = ext_map.get(lang, ".txt")
        
        filename = f"{problem_title.replace(' ', '_')}{ext}"
        filepath = os.path.join(output_folder, filename)
        
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(code)
            
        print(f"Solution saved to {filepath}")
        
    except requests.exceptions.RequestException as e:
        print(f"Error: {e}")
        if hasattr(e.response, 'text'):
            print("Response:", e.response.text[:500])
    except (KeyError, TypeError) as e:
        print(f"Data processing error: {e}")

def main():
    # Replace these with your actual values
    SESSION_COOKIE = "your_leetcode_session_cookie"
    CSRF_TOKEN = "your_csrf_token"
    USERNAME = "your_leetcode_username"
    PROBLEM_SLUG = "binary-tree-inorder-traversal"
    
    fetch_leetcode_submission(
        problem_slug=PROBLEM_SLUG,
        session_cookie=SESSION_COOKIE,
        csrf_token=CSRF_TOKEN,
        username=USERNAME
    )

if __name__ == "__main__":
    main()