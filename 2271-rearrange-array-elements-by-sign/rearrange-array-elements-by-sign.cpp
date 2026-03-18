class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> pos, neg;
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] > 0) {
        //         pos.push_back(nums[i]);
        //     } else {
        //         neg.push_back(nums[i]);
        //     }
        // }
        // vector<int> ans;
        // for (int i = 0; i < n/2; i++) {
        //     nums[2 * i] = pos[i];
        //     nums[2 * i + 1] = neg[i];
        // }
        // return nums;
        int n = nums.size();
        vector<int> ans(n,0);
        int posInd = 0;
        int negInd = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[posInd] = nums[i];
                posInd += 2;
            } else {
                ans[negInd] = nums[i];
                negInd += 2;
            }
        }
        return ans;
    }
};