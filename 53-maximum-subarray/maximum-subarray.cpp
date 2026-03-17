class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int maxSum=0;
        for(int i=0;i<nums.size();i++){
            maxSum+=nums[i];
            ans=max(ans,maxSum);
            if(maxSum<0){
                maxSum=0;
            }
        }
        return ans;
    }
};