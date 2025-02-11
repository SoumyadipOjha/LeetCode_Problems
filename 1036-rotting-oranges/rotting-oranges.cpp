class Solution {
public:
    bool isValid(int i, int j, int m, int n, vector<vector<int>>& grid) {
        return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0, time = 0;

        // Directions for up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Push all initially rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // BFS traversal
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            time++; // Increment time after processing one level of BFS

            for (int k = 0; k < size; k++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;

                    if (isValid(nx, ny, m, n, grid)) {
                        grid[nx][ny] = 2; // Mark orange as rotten
                        freshCount--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return (freshCount == 0) ? time : -1;
    }
};