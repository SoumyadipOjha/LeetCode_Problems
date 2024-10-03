class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = accumulate(nums.begin(), nums.end(),0LL); // Use 0LL to force long long

        int remainder = totalSum % p;

        if (remainder == 0)
            return 0;

        int n = nums.size();
        int minLength = n;
        int prefixSum = 0;
        unordered_map<int, int> prefixSums;

        prefixSums[0] = -1;

        for (int i = 0; i < n; i++) {
            prefixSum = (prefixSum + nums[i]) % p;
            int target = (prefixSum - remainder + p) % p;

            if (prefixSums.find(target) != prefixSums.end()) {
                minLength = min(minLength, i - prefixSums[target]);
            }

            prefixSums[prefixSum] = i;
        }

        return minLength == n ? -1 : minLength;
    }
};
