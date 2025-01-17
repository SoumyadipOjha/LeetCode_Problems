class Solution {
public:
int helper(vector<int>&coins,int i,int amount,vector<vector<int>>&dp){
    if(amount==0)return 0;
    if(amount<0 || i>=coins.size()){
        return INT_MAX-1;
    }
    if(dp[i][amount]!=-1)return dp[i][amount];
    int take=1+helper(coins,i,amount-coins[i],dp);
    int notTake=0+helper(coins,i+1,amount,dp);
    return dp[i][amount]=min(take,notTake);
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=helper(coins,0,amount,dp);
        if(ans!=INT_MAX-1)return ans;
        else{
            return -1;
        }
    }
};