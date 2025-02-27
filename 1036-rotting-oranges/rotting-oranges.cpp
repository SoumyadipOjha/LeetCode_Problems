class Solution {
public:
    int row[4] = {-1, +1, 0, 0};
    int col[4] = {0, 0, -1, +1};
    int r, c;
    bool isValid(int i, int j) { return (i >= 0 && i < r && j >= 0 && j < c); }

    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_oranges = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    fresh_oranges++;
            }
        }
        if (!fresh_oranges)
            return 0;
        int timer = 0;
        while (!q.empty()) {
            timer++;
            int curr_freshOranges = q.size();
            while (curr_freshOranges--) {
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