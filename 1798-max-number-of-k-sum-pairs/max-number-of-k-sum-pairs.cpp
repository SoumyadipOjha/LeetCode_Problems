class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            if(nums[left]+nums[right]==k){ans++;
            right--;left++;
            }
           else if(nums[left]+nums[right]<k)left++;
           else right--;
        }
        
        return ans;
    }
};