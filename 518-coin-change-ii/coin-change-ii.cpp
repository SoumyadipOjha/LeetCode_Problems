class Solution {
public:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>&dp) {
        if (amount == 0)
            return 1;
        if (i == coins.size())
            return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];
        if (coins[i] > amount) {
            return dp[i][amount] = solve(i + 1, amount, coins, dp);
        }
        int take = solve(i, amount - coins[i], coins, dp);
        int skip = solve(i + 1, amount, coins, dp);

        return dp[i][amount] = skip + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int i = 0;
        return solve(i, amount, coins, dp);
    }
};