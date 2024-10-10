class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n = nums.size();
        stack<int> st;

        st.push(0);

        for (int i = 1; i < n; i++) {
            if (nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        int ans = 0;

        for (int i = n - 1; i >= 0;) {

            while (!st.empty() and nums[st.top()] <= nums[i]) {
                ans = max(ans, i - st.top());
                st.pop();
            }

            if (st.empty())
                break;

            i--;
        }

        return ans;
    }
};
