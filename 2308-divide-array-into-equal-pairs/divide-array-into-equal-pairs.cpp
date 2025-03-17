class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int i: nums)
        map[i]++;
        for(auto i:map){
            if(i.second%2!=0)
            return false;
        }
        return true;
    }
};