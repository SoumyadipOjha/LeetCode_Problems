class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int totalSatisfied = 0;
        int maxAdditionalSatisfied = 0;
        int currentAdditionalSatisfied = 0;

        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                totalSatisfied += customers[i];
            } else if (i < k) {
                currentAdditionalSatisfied += customers[i];
            }
        }
        maxAdditionalSatisfied = currentAdditionalSatisfied;

        for (int i = k; i < customers.size(); ++i) {
            if (grumpy[i] == 1) {
                currentAdditionalSatisfied += customers[i];
            }
            if (grumpy[i - k] == 1) {
                currentAdditionalSatisfied -= customers[i - k];
            }
            maxAdditionalSatisfied =
                max(maxAdditionalSatisfied, currentAdditionalSatisfied);
        }

        return totalSatisfied + maxAdditionalSatisfied;
    }
};
