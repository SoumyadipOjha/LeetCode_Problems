class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> v;
        for (int i = 0; i < nums.size(); i++)
            v[nums[i]] = 1;
        for (int i = 1; i < nums.size() + 2; i++) {
            if (v.count(i) == 0)
                return i;
        }
        return 1;
    }
};
