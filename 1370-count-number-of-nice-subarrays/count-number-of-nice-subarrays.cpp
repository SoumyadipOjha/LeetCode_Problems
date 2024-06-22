class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int left = 0;
        int oddCount = 0;
        int validSubarrays =0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 != 0) {
                oddCount++;
                validSubarrays = 0;
            }

            while (oddCount == k) {
                validSubarrays++;
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }

            ans += validSubarrays;
        }

        return ans;
    }
};
