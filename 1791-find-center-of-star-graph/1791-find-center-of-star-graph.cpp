class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        int vertices = edges.size() + 1;

        vector<vector<int>> adj(vertices + 1);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i = 1; i <= vertices; i++) {
            if (adj[i].size() == vertices - 1)
                return i;
        }

        return -1;
    }
};