class Solution {
public:
    bool canFinish(int c, vector<vector<int>>& p) {
        vector<vector<int>> adjLs(c);
        vector<int> inDeg(c, 0);

        // Construct adjacency list & in-degree array
        for (const auto& a : p) {
            int u = a[1], v = a[0];
            adjLs[u].push_back(v);
            inDeg[v]++;
        }

        queue<int> q;
        int count = 0;

        // Push nodes with in-degree 0
        for (int i = 0; i < c; i++)
            if (inDeg[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int j = 0; j < adjLs[node].size(); j++) {
                inDeg[adjLs[node][j]]--; 
                if (inDeg[adjLs[node][j]] == 0)
                    q.push(adjLs[node][j]);
            }
        }

        return count == c;
    }
};
