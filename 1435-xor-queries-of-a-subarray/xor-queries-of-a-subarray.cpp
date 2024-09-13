class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int f = queries[i][0];
            int s = queries[i][1];
            int num = 0;
            for (int j = f; j <= s; j++) {
                num ^= arr[j];
            }
            ans.push_back(num);
        }
        return ans;
    }
};