class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> arr;
        int n = nums.size();
        int i = 0;

        while (i <= n - k) {
            bool isValid = true;
            int maxElem = nums[i];

            int j = i + 1;
            while (j < i + k) {
                if (nums[j] != nums[j - 1] + 1) {
                    isValid = false;
                    break;
                }
                maxElem = max(maxElem, nums[j]);
                ++j;
            }

            if (isValid) {
                arr.push_back(maxElem);
            } else {
                arr.push_back(-1);
            }

            ++i;
        }

        return arr;
    }
};
