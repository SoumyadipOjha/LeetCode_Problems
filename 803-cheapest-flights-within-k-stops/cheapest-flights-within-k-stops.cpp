#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights,
                          int src, int dst, int k) {
        std::vector<int> dp(n, std::numeric_limits<int>::max());
        dp[src] = 0;

        for (int i = 0; i <= k; i++) {
            std::vector<int> temp = dp;
            for (const auto& flight : flights) {
                if (dp[flight[0]] != std::numeric_limits<int>::max()) {
                    temp[flight[1]] =
                        std::min(temp[flight[1]], dp[flight[0]] + flight[2]);
                }
            }
            dp = temp;
        }

        return dp[dst] == std::numeric_limits<int>::max() ? -1 : dp[dst];
    }
};