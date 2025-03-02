class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adjLs(n);
        vector<int> inDeg(n, 0), courseTime(n, 0);

        // Build adjacency list and in-degree array
        for (auto& a : relations) {
            int u = a[0] - 1, v = a[1] - 1; // Convert to 0-based index
            adjLs[u].push_back(v);
            inDeg[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
                courseTime[i] = time[i]; //  Initialize time for independent courses
            }
        }

        // Topological sorting (BFS)
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 0; j < adjLs[node].size(); j++) {
                int neighbor = adjLs[node][j];
                inDeg[neighbor]--;

                //  Update the minimum time required to complete neighbor
                courseTime[neighbor] = max(courseTime[neighbor],
                                           courseTime[node] + time[neighbor]);

                if (inDeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return *max_element(courseTime.begin(), courseTime.end());
    }
};
