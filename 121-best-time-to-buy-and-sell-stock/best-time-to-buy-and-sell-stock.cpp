class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof=0;
        int mini=prices[0];
        for(int i =1;i<prices.size();i++){
            max_prof=max(max_prof,prices[i]-mini);
            mini=min(mini,prices[i]);
        }
        return max_prof;
    }
};