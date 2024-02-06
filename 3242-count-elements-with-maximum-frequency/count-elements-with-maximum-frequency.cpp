class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> map;
        for(auto it : nums){
            map[it]++;
            ans=max(ans,map[it]);
        }
        int res=0;
        for(auto it : map)
            if(it.second == ans) res+=it.second;
        return res;
    }
};