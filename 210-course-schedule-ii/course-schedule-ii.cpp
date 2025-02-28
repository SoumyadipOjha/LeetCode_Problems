class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> adjLs(n);
        vector<int> inDeg(n, 0);
        for (const auto& a : p) {
            int u = a[1];
            int v = a[0];
            inDeg[v]++;
            adjLs[u].push_back(v);
        }

        // push into queue
        queue<int> q;
        // find all the index with 0 inDeg and put into the q
        for (int i = 0; i < n; i++) {
            if (!inDeg[i])
                q.push(i);
        }
        vector<int> path;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            path.push_back(node);
            // check for neighbours
            for (int j = 0; j < adjLs[node].size(); j++) {
                inDeg[adjLs[node][j]]--;
                if (inDeg[adjLs[node][j]] == 0)
                    q.push(adjLs[node][j]);
            }
        }
        return (path.size() == n) ? path : vector<int>();
    }
};