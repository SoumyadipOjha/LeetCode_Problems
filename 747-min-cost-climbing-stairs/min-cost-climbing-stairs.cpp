class Solution {
public:
    int solve(vector<int>& cost, int n, vector<int>& dp) {
        // Base case
        if (n == 0 || n == 1)
            return cost[n];

        // Memoization check: step 3
        if (dp[n] != -1)
            return dp[n];

        // Recursive case: step 2
        dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));

        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // declare dp array :step1
        vector<int> dp(n + 1, -1); 
        return min(solve(cost, n - 1, dp),
                   solve(cost, n - 2,
                         dp)); 
    }
};
