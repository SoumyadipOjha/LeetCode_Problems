class Solution {
public:
    int m(string s) {
        int a = stoi(s.substr(0, 2)) * 60;
        int b = stoi(s.substr(3, 5));
        return a + b;
    }

    int findMinDifference(vector<string>& t) {
        vector<int> ans(t.size());
        for (int i = 0; i < t.size(); i++)
            ans[i] = m(t[i]);

        sort(ans.begin(), ans.end());
        int minDiff = INT_MAX;

        for (int i = 0; i < ans.size() - 1; i++) {
            int res = abs(ans[i] - ans[i + 1]);
            if (minDiff > res)
                minDiff = res;
        }
        int circularDiff = 1440 - (ans.back() - ans[0]);
        minDiff = min(minDiff, circularDiff);

        return minDiff;
    }
};
