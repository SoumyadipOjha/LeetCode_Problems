class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int max_diff = 0;
        int min = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - min > max_diff)
                max_diff = prices[i] - min;
            if (prices[i] < min)
                min = prices[i];
        }
        return max_diff;
    }
};
