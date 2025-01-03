class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int m = matrix.size(), n = matrix[0].size();
        // if (m == 1) {
        //     return *min_element(matrix[0].begin(), matrix[0].end());
        // }

        // for (int i = 1; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         int min_val = matrix[i - 1][j];
        //         if (j > 0) {
        //             min_val = min(min_val, matrix[i - 1][j - 1]);
        //         }
        //         if (j < n - 1) {
        //             min_val = min(min_val, matrix[i - 1][j + 1]);
        //         }
        //         matrix[i][j] += min_val;
        //     }
        // }

        // return *min_element(matrix[m - 1].begin(), matrix[m - 1].end());
        int m = matrix.size(), n = matrix[0].size();
        if (m == 1)
            return *min_element(matrix[0].begin(), matrix[0].end());
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int minV = matrix[i - 1][j];
                if (j <n-1)
                    minV = min(minV, matrix[i - 1][j + 1]);
                if (j > 0)
                    minV = min(matrix[i - 1][j -1], minV);
                matrix[i][j] += minV;
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};
