class Solution {
public:
    int minSteps(int n) {
        vector<int> v(n + 1, 1e9);
        v[1] = 0;
        vector<bool> prime(n, false);
        prime[0] = true, prime[1] = true;
        for (int i = 2; i <= n; i++) {
            if (prime[i] == false) {
                v[i] = i;
                for (int j = 2 * i; j <= n; j += i) {
                    prime[j] = true;
                    v[j] = (j / i) + v[i];
                }
            } else {
                for (int j = 2 * i; j <= n; j += i) {
                    prime[j] = true;
                    v[j] = min(v[j], (j / i) + v[i]);
                }
            }
        }
        return v[n];
    }
};
