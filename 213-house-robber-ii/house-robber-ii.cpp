class Solution {
public:
    int rob1(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int> skipFirst(nums.begin() + 1, nums.end());
        vector<int> skipLast(nums.begin(), nums.end() - 1);
        int s1 = rob1(skipFirst);
        int s2 = rob1(skipLast);
        return max(s1, s2);
    }
};
