import os
import requests
import json

# ✅ STEP 1: Configure your LeetCode username, problem name, and GitHub repo
USERNAME = "your_leetcode_username"  # Change this to your LeetCode username
PROBLEM_NAME = "Two Sum"  # Change this to the specific problem you want to push
FILE_EXTENSION = ".cpp"  # Change based on your language (".py" for Python, ".java" for Java)
leetcode_folder = "LeetCode-Solutions"  # Your local solutions folder

# ✅ STEP 2: Fetch solved problems using LeetCode API
api_url = "https://leetcode.com/graphql"
headers = {"Content-Type": "application/json"}
query = {
    "operationName": "getUserProfileQuestions",
    "query": '''
    query getUserProfileQuestions($username: String!) {
        matchedUser(username: $username) {
            submitStats {
                acSubmissionNum {
                    difficulty
                    count
                    submissions
                }
            }
            problemsSolvedBeatsStats {
                difficulty
                percentage
            }
        }
    }
    ''',
    "variables": {"username": USERNAME}
}

response = requests.post(api_url, headers=headers, data=json.dumps(query))

if response.status_code != 200:
    print("❌ Error: Could not fetch LeetCode profile. Check the username!")
    exit()

data = response.json()

# Extract solved problem count
if "data" in data and "matchedUser" in data["data"]:
    print(f"✅ Found LeetCode profile for {USERNAME}.")
else:
    print(f"❌ Error: Username '{USERNAME}' not found on LeetCode!")
    exit()

# ✅ STEP 3: Check if the solution file exists locally
file_name = PROBLEM_NAME.replace(" ", "_") + FILE_EXTENSION
file_path = os.path.join(leetcode_folder, file_name)

if not os.path.exists(leetcode_folder):
    print(f"❌ Error: Folder '{leetcode_folder}' does not exist!")
    exit()

if os.path.exists(file_path):
    print(f"✅ Found {file_name}, pushing to GitHub...")

    # Change to the directory
    #os.chdir(leetcode_folder)
    # ✅ STEP 4: Push to GitHub using Git commands
    os.system(f"git add .")
    os.system(f'git commit -m "Added solution for {PROBLEM_NAME}"')
    os.system("git push origin main")

    print("🚀 Successfully pushed to GitHub!")
else:
    print(f"❌ Error: {file_name} not found in {leetcode_folder}. Check the file name!")
