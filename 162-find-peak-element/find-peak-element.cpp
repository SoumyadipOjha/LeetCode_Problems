class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int max = INT_MIN;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (max < nums[i]) {
                max = nums[i];
                idx = i;
            }
        }
        return idx;
    }
};
