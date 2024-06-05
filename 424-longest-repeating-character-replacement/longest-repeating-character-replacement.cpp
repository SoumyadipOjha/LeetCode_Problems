class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int right=0,left=0,ans=0,maxi=0;
        unordered_map<char,int>map;
        while(right<n){
            map[s[right]]++;
            maxi=max(maxi,map[s[right]]);
            if((right-left+1)-maxi>k){
                map[s[left]]--;
                left++;
            }
            ans=max(ans,(right-left+1));
            right++;
        }
        return ans;
    }
};
