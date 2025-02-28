class Solution {
public:
    void DFS(int node, vector<vector<int>>& adjLs, vector<int>& vis) {
        vis[node] = 1;
        // check for neighbours
        for (int j = 0; j < adjLs[node].size(); j++) {
            if (!vis[adjLs[node][j]]) {
                DFS(adjLs[node][j], adjLs, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // base case
        if (n - 1 > connections.size())
            return -1;
        // make adjLs
        vector<vector<int>> adjLs(n);
        for (const auto& a : connections) {
            int u = a[1];
            int v = a[0];
            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }
        // call dfs and check number of component
        vector<int> vis(n, 0);
        int counter = 0;
        for (int i = 0; i < n; i++)
            if (!vis[i]) {
                counter++;
                DFS(i, adjLs, vis);
            }
        return counter - 1;
    }
};