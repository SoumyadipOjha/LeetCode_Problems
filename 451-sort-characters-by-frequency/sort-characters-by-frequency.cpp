class Solution {
public:
    string frequencySort(string s) {
        // string ans="";
        unordered_map<char, int> mp;
        for (auto i : s) {
            mp[i]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (mp[a] != mp[b])
                return mp[a] > mp[b];
            else
                return a < b;
        });

        return s;
    }
};