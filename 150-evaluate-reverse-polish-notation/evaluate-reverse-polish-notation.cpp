class Solution {
public:
    int evalRPN(vector<string>& a) {
        stack<int> s;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != "+" && a[i] != "-" && a[i] != "*" && a[i] != "/") {
                s.push(stoi(a[i]));
            } else {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                if (a[i] == "+") {
                    s.push(y + x);
                } else if (a[i] == "-") {
                    s.push(y - x);
                } else if (a[i] == "*") {
                    s.push(y * x);
                } else {
                    s.push(y / x);
                }
               
            }
        }
         return s.top();
    }
};