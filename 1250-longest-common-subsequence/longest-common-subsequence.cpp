class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int>dp(text2.length(),0);
        int longest=0;
        for(char c:text1){
            int curr=0;
            for(int i=0;i<dp.size();i++){
                if(curr<dp[i])curr=dp[i];
                else if(c==text2[i]){
                    dp[i]=curr+1;
                }
                longest=max(longest,dp[i]);
            }
        }
        return longest;
    }
};