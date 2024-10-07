class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int i = 0;
        while (i < s.size()) {
            char temp = s[i];
            if (!st.empty() && temp == 'B' && st.top() == 'A') {
                st.pop(); 
            } else if (!st.empty() && temp == 'D' && st.top() == 'C') {
                st.pop(); 
            } else {
                st.push(temp);
            }
            i++;
        }
        return st.size();
    }
};
