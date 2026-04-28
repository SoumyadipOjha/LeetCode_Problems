class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        // flatten grid
        for (auto& row : grid) {
            for (int v : row)
                arr.push_back(v);
        }

        // check possible
        int base = arr[0];
        for (int v : arr) {
            if (abs(v - base) % x != 0)
                return -1;
        }

        // sort
        sort(arr.begin(), arr.end());

        // median
        int median = arr[arr.size() / 2];

        // count operations
        int ops = 0;
        for (int v : arr) {
            ops += abs(v - median) / x;
        }

        return ops;
    }
};
