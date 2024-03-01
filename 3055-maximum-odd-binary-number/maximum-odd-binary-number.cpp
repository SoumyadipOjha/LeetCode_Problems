class Solution {
public:
    string maximumOddBinaryNumber(string s) {

        int n = s.size();
        int n1 = 0;
        int n0 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                n1++;
        }

        n0 = n - n1;

        string ans = "";

        while (n1 > 1) {
            ans += '1';
            n1--;
        }
        while (n0 > 0) {
            ans += '0';
            n0--;
        }
        ans += '1';

        return ans;
    }
};
