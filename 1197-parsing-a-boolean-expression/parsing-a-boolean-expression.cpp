class Solution {
public:
    bool parseBoolExpr(const std::string& expression) {
        std::stack<char> st;
        char temp = ' ', op = ' ';

        for (char ch : expression) {
            if (ch == '(' || ch == ',')
                continue;

            if (ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|')
                st.push(ch);
            else if (ch == ')') {

                bool hasTrue = false, hasFalse = false;

                while (!st.empty() && st.top() != '!' && st.top() != '&' &&
                       st.top() != '|') {
                    char val = st.top();
                    st.pop();
                    if (val == 't')
                        hasTrue = true;
                    if (val == 'f')
                        hasFalse = true;
                }

                if (!st.empty())
                    op = st.top(), st.pop();

                if (op == '!') {
                    temp = hasTrue ? 'f' : 't';
                } else if (op == '&') {
                    temp = (hasTrue && !hasFalse) ? 't' : 'f';
                } else if (op == '|') {
                    temp = hasTrue ? 't' : 'f';
                }
                st.push(temp);
            }
        }
        return st.top() == 't';
    }
};
