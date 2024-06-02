class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == " ")
            return 1;
        if (s.size() == 0)
            return 0;

        int maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> set;
            for (int j = i; j < s.size(); j++) {
                if (set.find(s[j]) != set.end()) {
                    break;
                }
                set.insert(s[j]);
                maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};
