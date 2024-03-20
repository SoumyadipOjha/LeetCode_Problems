class Solution {
public:
    int optimised_returner(int s, int e, vector<int>& nums) {
        int prev = nums[s], prev2 = 0;
        for (int i = s + 1; i < e; i++) {
            int pick = nums[i] + prev2; // for 1st iteration prev2 is already 0
            int curr =
                max(pick, prev); // not pick = prev so directly pass it in max
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int check1 = optimised_returner(0, n - 1, nums);
        int check2 = optimised_returner(1, n, nums);
        return max(check1, check2);
    }
};
