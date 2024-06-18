class Solution {
public:
    int minimumRecolors(string nums, int k) {
        int left = 0, right = 0, ans = INT_MAX, count = 0;
        while (right < nums.size()) {
            if (nums[right] == 'W')
                count++;
            if (right - left + 1 == k) {
                ans = min(ans, count);
                if (nums[left] == 'W') {
                    count--;
                   
                }
                 left++;
            }
            right++;
        }
        return ans;
    }
};