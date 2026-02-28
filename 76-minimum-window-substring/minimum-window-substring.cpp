class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap, sMap;
        for (char ch : t)
            tMap[ch]++;

        int count = 0, beg = 0, len = INT_MAX;
        for (int l = 0, r = 0; r < s.size(); r++) {
            sMap[s[r]]++;
            if (sMap[s[r]] <= tMap[s[r]])
                count++;
            while (count == t.size()) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    beg = l;
                }
                if (sMap[s[l]] > tMap[s[l]]) {
                    sMap[s[l]]--;
                    l++;
                } else
                    break;
            }
        }
        if (len == INT_MAX)
            len = 0;
        return s.substr(beg, len);
    }
};
