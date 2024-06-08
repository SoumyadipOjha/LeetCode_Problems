class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // Unordered Map for finding sum of subarrays
        unordered_map<int, int> mp;

        // This is used to handle cases whne subarray starts with index 0
        mp[0] = -1;

        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            // Here, checks if remainder exists before or not..
            if (mp.find((sum % k)) != mp.end()) {
                // Checking gap between current & remainder containing index..
                // If it is more than 1 , return true..
                if (i - mp[sum % k] > 1)
                    return true;
            } else {
                // Else set value of rem to given index
                mp[sum % k] = i;
            }
        }

        // Return false otherwise..
        return false;
    }
};
