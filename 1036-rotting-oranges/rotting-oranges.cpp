class Solution {
public:
    int r, c;
    int row[4] = {-1, +1, 0, 0};
    int col[4] = {0, 0, -1, +1};
    bool isValid(int i, int j) { return (i >= 0 && i < r && j >= 0 && j < c); }
    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});

                if (grid[i][j] == 1)
                    fresh++;
            }

        if (fresh == 0) {
            return 0;
        }
        int timer = 0;
        while (!q.empty()) {
            timer++;
            int curr_fresh = q.size();
            while (curr_fresh--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    if (isValid(i + row[k], j + col[k]) &&
                        grid[i + row[k]][j + col[k]] == 1) {
                        grid[i + row[k]][j + col[k]] = 2;
                        q.push({i + row[k], j + col[k]});
                    }
                }
            }
        }
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 1)
                    return -1;

        return timer - 1;
    }
};