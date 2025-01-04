class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1)return 0;
        vector<int>dp(amount+1);
        for(int i=1;i<=amount;i++){
            dp[i]=INT_MAX;
            for(int c:coins){
                if(c<=i && dp[i-c]!=INT_MAX){
                    dp[i]=min(dp[i],1+dp[i-c]);
                }
            }
        }
        if(dp[amount]==INT_MAX)return -1;
        else{
            return dp[amount];
        }

    }
};