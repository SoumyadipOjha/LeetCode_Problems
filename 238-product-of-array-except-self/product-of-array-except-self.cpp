class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int>l;
       l.push_back(1);
       for(int i=0;i<nums.size();i++){
        l.push_back(l[i]*nums[i]);
       }
       int product=1;
       for(int i=nums.size()-1;i>0;i--){
        int initial=nums[i];
        nums[i]=l[i]*product;
        product=product*initial;
       }
       nums[0]=product;
       return nums;

    }
};