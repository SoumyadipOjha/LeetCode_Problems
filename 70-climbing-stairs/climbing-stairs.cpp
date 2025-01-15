class Solution {
public:
    int climbStairs(int n) {
        // recur
        // if(n<=2)return n;
        // return dp[n]=climbStairs(n-1)+climbStairs(n-2);

        // memo
        // vector<int>dp(n+1,-1);
        // if(n<=2)return n;
        // if(dp[n]!=-1)return dp[n];
        // return dp[n]=climbStairs(n-1)+climbStairs(n-2);

        // teabu
        // vector<int> dp(n + 1, 0);
        // dp[0] = 1;
        // dp[1] = 1;
        // for (int i = 2; i <= n; i++) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];

        // space opt
        if (n <= 0)
            return 0; 
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int p1 = 1, p2 = 2;
        for (int i = 3; i <= n; i++) {
            int ans = p1 + p2;
            p1 = p2;
            p2 = ans;
        }
        return p2;
    }
};