class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int num : nums1)
            mp[num]++;
        vector<int> res;
        for (int num : nums2) {
            if (mp[num] > 0) {
                res.push_back(num);
                mp[num] = 0;
            }
        }
        return res;
    }
};
