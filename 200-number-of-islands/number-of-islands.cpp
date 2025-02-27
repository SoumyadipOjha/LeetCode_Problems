class Solution {
public:
    int r, c;
    int row[4] = {-1, +1, 0, 0};
    int col[4] = {0, 0, -1, +1};
    bool isValid(int i, int j){
        return (i>=0 && i<r && j>=0 && j<c);
    }
    int numIslands(vector<vector<char>>& isConnected) {
        r = isConnected.size();
        c = isConnected[0].size();
        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (isConnected[i][j] == '1') {
                    count++;
                    isConnected[i][j] = '0';
                    q.push({i, j});
                    while (!q.empty()) {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            if (isValid(new_i + row[k], new_j + col[k]) &&
                                isConnected[new_i + row[k]][new_j + col[k]] ==
                                    '1') {
                                isConnected[new_i + row[k]][new_j + col[k]] = '0';
                                q.push({new_i + row[k], new_j + col[k]});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
