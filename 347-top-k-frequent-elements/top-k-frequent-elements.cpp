class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second > b.second;
             });
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(vec[i].first);
        }
        return res;
    }
};