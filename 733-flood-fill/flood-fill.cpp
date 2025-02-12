class Solution {
private:
    bool isValid(int i, int j, vector<vector<int>>& image,
                 vector<vector<int>>& ans, int iniCol, int newCol) {
        int n = image.size();
        int m = image[0].size();
        return (i >= 0 && i < n && j >= 0 && j < m && image[i][j] == iniCol &&
                ans[i][j] != newCol);
    }
    void dfs(int row, int col, vector<vector<int>>& image,
             vector<vector<int>>& ans, int iniCol, int newCol,
             vector<int>& delRow, vector<int>& delCol) {
        ans[row][col] = newCol;
        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if (isValid(nRow, nCol, image, ans, iniCol, newCol)) {
                dfs(nRow, nCol, image, ans, iniCol, newCol, delRow, delCol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int iniCol = image[sr][sc];
        if (iniCol == color)
            return image;
        vector<vector<int>> ans = image;

        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        dfs(sr, sc, image, ans, iniCol, color, delRow, delCol);
        return ans;
    }
};