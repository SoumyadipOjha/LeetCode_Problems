class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {

        int n = A.size(), i;
        vector<int> res;
        priority_queue<pair<int, int>> q;

        for (i = 0; i < k; i++)
            q.push({A[i], i});
        res.push_back(q.top().first);

        for (; i < n; i++) {
            while (!q.empty() && q.top().second <= i - k)
                q.pop();
            q.push({A[i], i});
            res.push_back(q.top().first);
        }
        return res;
    }
}

;