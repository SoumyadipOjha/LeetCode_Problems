class Solution {
public:
    int pivotInteger(int n) {
        int pivot = 1;
        int TotalSum = n * (n + 1) / 2;
        while (pivot <= n) {
            int sum = pivot * (pivot + 1) / 2;
            if (sum == TotalSum + pivot - sum)
                return pivot;
            pivot++;
        }
        return -1;
    }
};
