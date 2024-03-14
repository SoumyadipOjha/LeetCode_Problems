class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int,int>mp;
     int count=0,sum=0;
     mp[0]=1;
     for(auto i:nums){
        sum+=i;
        if(mp.find(sum-k)!=mp.end()){
            count+=mp[sum-k];
        }
        mp[sum]++;
     }   
     return count;
    }
};