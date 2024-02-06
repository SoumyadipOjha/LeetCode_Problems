class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> m;
        int index = 0;
        // if (strs[0].size() == 0) {
        //     ans.push_back({""});
        //     return ans;
        // }
        for (int i = 0; i < strs.size(); i++) {
            string s1 = strs[i];
            sort(s1.begin(), s1.end());
            if (m.find(s1) != m.end()) {
                ans[m[s1]].push_back(strs[i]);
            } else {
                m[s1]=index++;
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};