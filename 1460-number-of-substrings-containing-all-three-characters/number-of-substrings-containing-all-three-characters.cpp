class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0);
        int res = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'a']++;
            while (count[0] && count[1] && count[2]) {
                res += s.size() - right;
                count[s[left++] - 'a']--;
            }
        }
        return res;
    }
};