class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // vector<int>sum(nums.size());
        // sum[0]=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     sum[i]=sum[i-1]+nums[i];
        // }
        // return sum;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            nums[i]=sum;
        }
        return nums;
    }
};