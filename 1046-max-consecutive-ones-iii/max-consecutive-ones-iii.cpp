class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int right=0,left=0,ans=0,flip=0,n=nums.size();
      for(right=0;right<n;right++){
        if(nums[right]==0){
            flip++;
        }
        while(flip>k){
            if(nums[left]==0){
                flip--;
            }
            left++;
        }
        ans=max(ans,right-left+1);
      }
      return ans;
    }
};