class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& inter1, const vector<int>& inter2) -> bool {
                 return inter1[1] < inter2[1];
             });
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int indx = 1; indx < intervals.size(); indx++) {
            int currEnd = intervals[indx][1], currStart = intervals[indx][0];
            while (res.size() > 0 && res[res.size() - 1][1] >= currStart) {
                currEnd = max(res[res.size() - 1][1], currEnd);
                currStart = min(res[res.size() - 1][0], currStart);
                res.pop_back();
            }
            res.push_back({currStart, currEnd});
        }
        return res;
    }
};
