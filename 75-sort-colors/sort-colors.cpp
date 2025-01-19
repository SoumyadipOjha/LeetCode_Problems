class Solution {
public:
    void sortColors(vector<int>& nums) {

        if(nums.size()==0)cout<<"";
        int min=nums[0],max=nums[0];
        for(int i:nums){
            if(i<min)min=i;
            if(i>max)max=i;
        }
        int range=max-min+1;
        vector<int>count(range,0);
        for(int i:nums)count[i-min]++;

        int index=0;
        for(int i=0;i<range;i++){
            while(count[i]>0){
                nums[index++]=i+min;
                count[i]--;
            }
        }
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
        }
    }
};