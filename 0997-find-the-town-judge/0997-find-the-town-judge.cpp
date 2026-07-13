class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < trust.size(); i++) {
            adj[trust[i][0]].push_back(trust[i][1]);
        }

        for (int candidate = 1; candidate <= n; candidate++) {

            if (adj[candidate].size() != 0)
                continue;

            bool judge = true;

            for (int person = 1; person <= n; person++) {

                if (person == candidate)
                    continue;

                bool found = false;

                for (int trustedPerson : adj[person]) {
                    if (trustedPerson == candidate) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    judge = false;
                    break;
                }
            }

            if (judge)
                return candidate;
        }

        return -1;
    }
};