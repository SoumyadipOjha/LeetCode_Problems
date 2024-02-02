#include <vector>


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo <= hi) {
            int m = (lo + hi) / 2;
            if (nums[m] > target)  hi = m - 1;
            else if (nums[m] < target)  lo = m + 1;
            else return m;
        }

        return -1;
    }
};