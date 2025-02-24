class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int diff = INT_MAX;
        char c = letters[0];
        for (int i = 0; i < letters.size(); i++) {
            if (letters[i]>target) {
                int d = letters[i] - target;
                if (d < diff) {
                    diff = d;
                    c = letters[i];
                }
            }
        }
        return c;
    }
};