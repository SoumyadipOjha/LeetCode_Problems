class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // if (amount < 1)
        //     return 0;
        // vector<int> minCoinsDP(amount + 1);
        // for (int i = 1; i <= amount; i++) {

        //     minCoinsDP[i] = INT_MAX;

        //     // Try each coin
        //     for (int coin : coins) {
        //         if (coin <= i && minCoinsDP[i - coin] != INT_MAX)
        //             minCoinsDP[i] =
        //                 min(minCoinsDP[i], 1 + minCoinsDP[i - coin]);
        //     }
        // }

        // if (minCoinsDP[amount] == INT_MAX)
        //     return -1;
        // else {
        //     return minCoinsDP[amount];
        // }
        if(amount<1)return 0;
        vector<int>dp(amount+1);
        for(int i=1;i<=amount;i++){
            dp[i]=INT_MAX;
            for(int c:coins){
                if(c<=i && dp[i-c]!=INT_MAX)dp[i]=min(dp[i],1+dp[i-c]);
            }
        }
        if(dp[amount]==INT_MAX)return -1;
        else {
            return dp[amount];
        }

    }
};