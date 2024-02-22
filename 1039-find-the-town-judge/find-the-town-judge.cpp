class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1,0); // Initialize trust count for each person
        for (int i=0;i<trust.size();i++) {
            trustCount[trust[i][0]]--; // Someone trusts
            trustCount[trust[i][1]]++; // Someone is trusted
        }

        for (int i = 1; i <= n; i++) {
            if (trustCount[i] == n - 1) { // Check if everyone trusts this
                                          // person except themselves
                return i;
            }
        }

        return -1; // No judge found
    }
};
