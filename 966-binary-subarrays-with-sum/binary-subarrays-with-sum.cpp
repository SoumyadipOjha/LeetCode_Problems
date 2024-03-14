class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       unordered_map<int,int>mp;
       mp[0]=1;
       int sum=0,count=0;
       for(auto i:nums){
        sum+=i;
        if(mp.find(sum-goal)!=mp.end()){
            count+=mp[sum-goal];
        }
        mp[sum]++;
       }
       return count;
    }
};
