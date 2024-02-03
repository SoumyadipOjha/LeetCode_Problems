class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1);
        int n = arr.size();

        for(int i = 1; i<= arr.size(); i++){
            int maxi = 0 , ans=0;
            for(int j = 1;j<= k and i-j>=0; j++){
                cout<<i-j<<max(0,i-j)<<endl;

                maxi = max(maxi, arr[i-j]);
                ans = max(ans, dp[i-j]+maxi*(j));
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};