class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, vector<int>>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {positions[i], {i, healths[i], directions[i]}};
        }
        sort(v.begin(), v.end());
        stack<pair<int, vector<int>>> st;
        vector<pair<int, vector<int>>> ans;
        for (int i = 0; i < n; i++) {
            if (v[i].second[2] == 'R') {
                st.push(v[i]);
            } else {
                bool insert = true;
                while (!st.empty()) {
                    pair<int, vector<int>> top = st.top();
                    st.pop();
                    if (top.second[1] == v[i].second[1]) {
                        insert = false;
                        break;
                    } else if (top.second[1] > v[i].second[1]) {
                        insert = false;
                        top.second[1]--;
                        st.push(top);
                        break;
                    } else {
                        v[i].second[1]--;
                        continue;
                    }
                }
                if (insert) {
                    ans.push_back(v[i]);
                }
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        for (int i = 0; i < ans.size(); i++) {
            pair<int, vector<int>> temp = ans[i];
            ans[i].first = temp.second[0];
            ans[i].second[0] = temp.first;
        }
        sort(ans.begin(), ans.end());
        vector<int> res;
        for (int i = 0; i < ans.size(); i++) {
            res.push_back(ans[i].second[1]);
        }
        return res;
    }
};
