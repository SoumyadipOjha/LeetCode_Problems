class Solution {
public:
    int maxScore(string s) {
        int result = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            int curr = 0;
            for (int j = 0; j <= i; j++) {
                if (s[j] == '0')
                    curr++;
            }
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == '1')
                    curr++;
            }
            result = max(result, curr);
        }
        return result;
    }
};