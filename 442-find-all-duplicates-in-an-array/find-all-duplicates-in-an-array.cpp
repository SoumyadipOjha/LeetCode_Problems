class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int i:nums){
            map[i]++;
        }
        vector<int>ans;
        for(auto i:map){
            if(i.second==2){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};