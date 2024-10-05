// Approach - 02 - Sliding Window
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if (m > n)
            return false; // If s1 is longer than s2, no permutation is
                          // possible.

        // Frequency arrays for s1 and the current window in s2
        vector<int> s1_freq(26, 0), window_freq(26, 0);

        // Count frequency array for s1
        for (char c : s1) {
            s1_freq[c - 'a']++;
        }

        // Initialize the first window of size m in s2
        for (int i = 0; i < m; i++) {
            window_freq[s2[i] - 'a']++;
        }

        // Slide the window over the string s2
        for (int i = 0; i <= n - m; i++) {
            // If frequencies match, we found a valid permutation
            if (s1_freq == window_freq) {
                return true;
            }

            // Slide the window to the right:
            if (i + m < n) {
                // Remove the first character of the current window
                window_freq[s2[i] - 'a']--;
                // Add the next character to the window
                window_freq[s2[i + m] - 'a']++;
            }
        }

        // Check the last window
        return s1_freq == window_freq;
    }
};