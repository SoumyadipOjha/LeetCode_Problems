class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int>map;
      vector<int>res;
      for(auto i:nums){
        map[i]++;
      }
      vector<pair<int,int>>ans;
      for(auto i:map){
        ans.push_back({i.second,i.first});
      }
      sort(ans.begin(),ans.end());
      for(int i=ans.size()-1;k!=0;i--){
        res.push_back(ans[i].second);
        k--;
      }
      return res;
    }
};