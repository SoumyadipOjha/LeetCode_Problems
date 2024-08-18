class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> k(points[0].begin(), points[0].end());
        for (int i = 1; i < m; ++i) {

            for (int j = 1; j < n; ++j) {
                k[j] = max(k[j], k[j - 1] - 1);
            }
            for (int j = n - 2; j >= 0; --j) {
                k[j] = max(k[j], k[j + 1] - 1);
            }
            for (int j = 0; j < n; ++j) {
                k[j] += points[i][j];
            }
        }
        return *max_element(k.begin(), k.end());
    }
};
