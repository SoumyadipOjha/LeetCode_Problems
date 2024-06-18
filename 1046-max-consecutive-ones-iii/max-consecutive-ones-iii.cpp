class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int left=0,right=0,ans=0,flip=0;int n=nums.size();
      for(right=0;right<n;right++){
        if(nums[right]==0)flip++;
        while(flip>k){
            if(nums[left]==0)flip--;
            left++;
        }
        ans=max(ans,right-left+1);
      }
      return ans;
    }
};