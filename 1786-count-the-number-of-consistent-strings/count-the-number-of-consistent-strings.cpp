class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> set(allowed.begin(), allowed.end());
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            string a = words[i];
            bool consistent = true;
            for (char ch : a) {
                if (set.find(ch) == set.end()) {
                    consistent = false;
                    break;
                }
            }
            if (consistent)
                ans++;
        }
        return ans;
    }
};
