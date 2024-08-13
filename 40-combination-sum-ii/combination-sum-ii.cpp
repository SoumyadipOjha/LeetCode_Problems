class Solution {
public:
    int sum = 0;
    vector<vector<int>> ans;
    vector<int> tmp;

    void dfs(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.push_back(tmp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            tmp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);

        return ans;
    }
};
