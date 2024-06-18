class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0, right = 0, count = 0, ans = INT_MIN;
        while (right < s.size()) {
            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' ||
                s[right] == 'o' || s[right] == 'u')
                count++;
            if (right - left + 1 == k) {
                ans = max(ans, count);
                if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' ||
                    s[left] == 'o' || s[left] == 'u') {
                    count--;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};