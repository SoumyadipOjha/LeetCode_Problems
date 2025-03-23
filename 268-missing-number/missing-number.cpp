class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size()+1;
        int ans=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=i+1;
            ans+=nums[i];
        }
        return total-ans;
    }
};