class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Check if mid is the target
            if (nums[mid] == target)
                return mid;

            // Determine which side is sorted
            if (nums[s] <= nums[mid]) {
                // Left part is sorted
                if (target >= nums[s] && target < nums[mid]) {
                    e = mid - 1; // Target is in the sorted left part
                } else {
                    s = mid + 1; // Target is in the right part
                }
            } else {
                // Right part is sorted
                if (target > nums[mid] && target <= nums[e]) {
                    s = mid + 1; // Target is in the sorted right part
                } else {
                    e = mid - 1; // Target is in the left part
                }
            }
        }

        return -1; // Target not found
    }
};
