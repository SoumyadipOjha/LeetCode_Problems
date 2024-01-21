class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1= 0,curr=0;
        int n = nums.size();
        if(n==1) return nums[0];
        for(auto num: nums){
            curr = max(prev2+num,prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};