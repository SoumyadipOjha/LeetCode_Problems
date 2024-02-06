class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        int maxFreq = INT_MIN;
        for(auto& it:map){
            if(maxFreq < it.second){
                maxFreq = it.second;
            }
        }
        int count = 0;
        for(auto& it:map){
            if(it.second == maxFreq){
                count += maxFreq;
            }
        }
        return count;
    }
};