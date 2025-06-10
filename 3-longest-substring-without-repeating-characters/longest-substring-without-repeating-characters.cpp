class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>count(256,0);
        int first=0,second=0,len=0;
        while(second<s.size()){
            while(count[s[second]]){
                count[s[first]]=0;
                first++;
            }
            count[s[second]]=1;
            second++;
            len=max(len,second-first);
        }
        return len;
    }
};