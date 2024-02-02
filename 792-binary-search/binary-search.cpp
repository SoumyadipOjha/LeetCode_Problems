class Solution {
public:
    int search(vector<int>& nums, int target) {
       int st=0;
       int end=nums.size();
       while(st<end){
           int mid=st+(end-st)/2;
           if(target==nums[mid]){
               return mid;
           }
           if(target>nums[mid]){
               st=mid+1;
           }
           if(target<nums[mid]){
               end=mid;
           }
       } 
       return -1;
    }
};