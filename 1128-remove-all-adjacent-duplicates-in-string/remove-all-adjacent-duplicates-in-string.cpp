class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string s1 = "";
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top() == s[i])
                st.pop();
            else {
                st.push(s[i]);
            }
        }
        while (!st.empty()) {
            s1 = st.top() + s1;
            st.pop();
        }

        return s1;
    }
};