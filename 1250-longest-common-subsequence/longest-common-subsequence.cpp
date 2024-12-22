class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text1.length(), 0);
        int longest = 0;

        for (char c : text2) {
            int curLength = 0;
            for (int i = 0; i < dp.size(); i++) {
                if (curLength < dp[i]) {
                    curLength = dp[i];
                } else if (text1[i] == c) {
                    dp[i] = curLength + 1;
                }
                longest = max(longest, dp[i]);
            }
        }
        return longest;
    }
};
