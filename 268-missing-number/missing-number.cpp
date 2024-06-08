class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;int a=0;
        for(int i=0;i<nums.size();i++){
            a+=i+1;
            sum+=nums[i];
        }
        return abs(sum-a);
    }
};