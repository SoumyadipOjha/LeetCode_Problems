class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1), suf(n, 1), ans(n, 1);

        // Compute prefix products
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i];
        }

        // Compute suffix products
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] * nums[i];
        }

        // Compute result using prefix and suffix products
        for (int i = 0; i < n; i++) {
            int left = (i > 0) ? pre[i - 1] : 1;
            int right = (i < n - 1) ? suf[i + 1] : 1;
            ans[i] = left * right;
        }

        return ans;
    }
};
