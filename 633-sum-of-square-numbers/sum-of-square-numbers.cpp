class Solution {
public:
    bool judgeSquareSum(int c) {

        long long i = 0;
        long long j = sqrt(c);
        while (i <= j) {
            long long ans = i * i + j * j;
            if (ans < c) {
                i++;
            } else if (ans > c) {
                j--;
            } else if (ans == c) {
                return true;
            }
        }
        return false;
    }
};
