class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // if(target>nums[nums.size()-1]){
        //     return nums.size();
        // }
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target){
        //         return i;
        //         break;
        //     }
        //     else{
        //         if(target<nums[i]){
        //             return i;
        //             break;
        //         }
        //     }
        // }
        // return 0;
        int low=0;
        int high=nums.size();
        if(target>nums[high-1]){
            return high;
        }
       while(low<=high){
              int mid=low+(high-low)/2;
            if(nums[mid]==target){  
                return mid;
            }
          
            if(target<nums[mid]){     
            high=mid-1;    
            }else{
            low=mid+1;        
            }
          
        }
         return  low;   

    }
};