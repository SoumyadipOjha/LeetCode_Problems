class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> arr;
        int n = nums.size();

        for (int i = 0; i <= n - k; ++i) {
            bool isValid = true;
            int maxElem = nums[i];

            for (int j = i + 1; j < i + k; ++j) {
                if (nums[j] != nums[j - 1] + 1) {
                    isValid = false;
                    break;
                }
                maxElem = max(maxElem, nums[j]);
            }

            if (isValid) {
                arr.push_back(maxElem);
            } else {
                arr.push_back(-1);
            }
        }

        return arr;
    }
};