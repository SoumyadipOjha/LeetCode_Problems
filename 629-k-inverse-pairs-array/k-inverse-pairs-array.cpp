class Solution {
    int dp[1001][1001], mod = 1e9 + 7;
    long long dfs(int n, int k) {
        if (n == 0)
            return 0;
        if (k == 0)
            return 1;
        if (dp[n][k] != -1)
            return dp[n][k];
        long long last = min(k, n - 1), ans = 0;
        for (int i = 0; i <= last; i++)
            ans = (ans + dfs(n - 1, k - i)) % mod;
        return dp[n][k] = ans % mod;
    }

public:
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(n, k) % mod;
    }
};