class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
                   ? edges[0][0]
                   : edges[0][1];
    }
};
// if you upvote you will hear good news in 10mins (those who are waiting for a
// job will get job offer in a week)
