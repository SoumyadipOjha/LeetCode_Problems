class Solution {
public:
    bool isIsomorphic(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        int freq1[256] = {0};
        int freq2[256] = {0};
        if (m != n)
            return false;
        for (int i = 0; i < n; i++) {
            if (freq1[str1[i]] == 0 && freq2[str2[i]] == 0) {
                freq1[str1[i]] = str2[i];
                freq2[str2[i]] = str1[i];
            } else if (freq1[str1[i]] != str2[i])
                return false;
        }
        return true;
    }
};
