class TopVotedCandidate {
private:
    vector<int> leaders;      // Stores the leader at each vote time
    vector<int> voteTimes;    // Stores the time of each vote

public:
    // Constructor
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> voteCount; // Keeps track of votes per person
        int currentLeader = -1;            // Tracks current leader
        int maxVotes = 0;                  // Tracks highest vote count

        // Go through each vote
        for (int i = 0; i < persons.size(); ++i) {
            int person = persons[i];
            int time = times[i];

            // Increase the vote count for the current person
            voteCount[person]++;

            // Update the leader if this person has more or equal votes
            if (voteCount[person] >= maxVotes) {
                currentLeader = person;
                maxVotes = voteCount[person];
            }

            // Store current leader at this time
            leaders.push_back(currentLeader);
        }

        // Save the vote times
        voteTimes = times;
    }

    // Query function: returns leader at time t
    int q(int t) {
        // Binary search to find the last time ≤ t
        int left = 0, right = voteTimes.size() - 1;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            if (voteTimes[mid] <= t)
                left = mid;
            else
                right = mid - 1;
        }

        // Return the leader at that time
        return leaders[left];
    }
};
