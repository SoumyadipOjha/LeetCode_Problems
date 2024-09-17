class Solution {
public:
    bool isValid(string s) {
        stack<char> helper;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == ')' && helper.size() > 0 && helper.top() == '(') {
                helper.pop();
            } else if (s[i] == '}' && helper.size() > 0 &&
                       helper.top() == '{') {
                helper.pop();
            } else if (s[i] == ']' && helper.size() > 0 &&
                       helper.top() == '[') {
                helper.pop();
            } else {
                helper.push(s[i]);
            }
        }

        if (helper.size() == 0) {
            return true;
        }
        return false;
    }
};
