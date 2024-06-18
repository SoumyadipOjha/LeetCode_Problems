class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0, ans = 0, cnt = 0;
        while (right < nums.size()) {
            if (nums[right] == 0)
                cnt++;
            while (cnt > 1) {
                if (nums[left] == 0)
                    cnt--;
                left++;
            }
            ans = max(ans, right - left +1);
            right++;
        }
        return ans-1;
    }
};