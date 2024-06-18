class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int zeroes = 0;
        int n = nums.size();
        int ans = 0;
        while (j < n) {
            if (nums[j] == 0)
                zeroes++;
            while (zeroes > 1) {
                if (nums[i] == 0)
                    zeroes--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans - 1;
    }
};
