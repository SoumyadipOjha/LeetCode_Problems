class Solution {
public:
    vector<int> solve(string exp) {
        // start
        // leap of faith recursion
        vector<int> ans;
        for (int i = 0; i < exp.length(); i++) {
            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
                // split up
                vector<int> nums1 = solve(exp.substr(0, i));
                vector<int> nums2 = solve(exp.substr(i + 1));

                for (int& n1 : nums1) {
                    for (int& n2 : nums2) {
                        //  cout<<n1<<" "<<n2<<endl;
                        if (exp[i] == '+') {
                            ans.push_back(n1 + n2);
                        } else if (exp[i] == '-') {
                            ans.push_back(n1 - n2);
                        }

                        else
                            ans.push_back(n1 * n2);
                    }
                }
            }
        }
        if (ans.empty()) {
            // cout<<i<<endl;
            ans.push_back(stoi(exp));
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
