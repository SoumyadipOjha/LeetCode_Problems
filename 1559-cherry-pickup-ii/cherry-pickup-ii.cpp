class Solution {
public:
    int picking(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid,
                vector<vector<vector<int>>>& dp) {
        if (i >= n || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return 0;
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int candy = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                dp[i][j1][j2] =
                    max(dp[i][j1][j2],
                        candy + picking(i + 1, j1 + x, j2 + y, n, m, grid, dp));
            }
        }
        return dp[i][j1][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));
        return picking(0, 0, m - 1, n, m, grid, dp);
    }
};