class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int sum1=0;
        // int n=nums.size()+1;
        // for(int i=0;i<n;i++){
        //     sum1+=i;
        // }
        // int sum2=0;
        // for(int i=0;i<nums.size();i++){
        //     sum2+=nums[i];
        // }
        // return sum1-sum2;
        
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int s2 = 0;
        for (int i = 0; i < n; i++) {
            s2 += nums[i];
        }
        return sum - s2;
    }
};