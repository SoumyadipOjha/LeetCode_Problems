class Solution {
public:
    int longestPalindrome(string s) {
      int count=0;
      unordered_map<char,int>map;
      for(auto x:s){
        map[x]++;
      } 
      for(auto x:map){
        if(x.second>1){
            count+=x.second-(x.second%2);
        }
      }
      if(count<s.size()){
        count+=1;
      }
      return count;
    }
};