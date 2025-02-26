class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN, sum = 0, left = 0, right = 0;
        while (right < nums.size()) {
            if (sum < 0 && nums[right] >= sum) {
                left = right;
                sum = 0;
            }
            sum += nums[right];
            maxi = max(maxi, sum);
            right++;
        }
        return maxi;
    }
};