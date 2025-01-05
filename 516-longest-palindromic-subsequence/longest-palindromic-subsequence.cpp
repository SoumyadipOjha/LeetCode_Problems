class Solution {
public:
    int longestCommonSubSequence(string s, string revS) {
        int longest = 0;
        vector<int> dp(revS.size(), 0);
        for (char c : s) {
            int curr = 0;
            for (int i = 0; i < dp.size(); i++) {
                if (curr < dp[i])
                    curr = dp[i];
                else if (c == revS[i])
                    dp[i] = curr + 1;
                longest = max(longest, dp[i]);
            }
        }
        return longest;
    }
    int longestPalindromeSubseq(string s) {
        string revS = s;
        reverse(revS.begin(), revS.end());
        return longestCommonSubSequence(s, revS);
    }
};