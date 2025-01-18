class Solution {
public:
    int first(vector<int> arr, int k) {
        int s = 0, e = arr.size() - 1, mid, ans = -1;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (arr[mid] == k) {
                ans = mid;
                e = mid - 1;
            } else if (k > arr[mid]) {
                s = mid + 1;
            } else
                e = mid - 1;
        }
        return ans;
    }
    int last(vector<int> arr, int k) {
        int s = 0, e = arr.size() - 1, mid, ans = -1;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (arr[mid] == k) {
                ans = mid;
                s = mid + 1;
            } else if (k > arr[mid]) {
                s = mid + 1;
            } else
                e = mid - 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> ans;
        ans.push_back(first(arr, target));
        ans.push_back(last(arr, target));
        return ans;
    }
};
