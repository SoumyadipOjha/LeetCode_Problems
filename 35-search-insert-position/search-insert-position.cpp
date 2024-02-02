class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target>nums[nums.size()-1]){
            return nums.size();
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
                break;
            }
            else{
                if(target<nums[i]){
                    return i;
                    break;
                }
            }
        }
        return 0;
    }
};