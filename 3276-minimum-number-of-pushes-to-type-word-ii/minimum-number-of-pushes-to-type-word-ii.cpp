class Solution {
public:
    int minimumPushes(string word) {
        int res = 0, freq[26] = {};
        for (char c : word)
            freq[c - 'a']++;
        sort(begin(freq), end(freq), greater<int>());
        for (int i = 0; i < 26 && freq[i]; i++)
            res += freq[i] * (i / 8 + 1);
        return res;
    }
};
