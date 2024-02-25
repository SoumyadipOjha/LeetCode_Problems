class union_find {
public:
    vector<int> p;
    vector<int> r;
    union_find(int n) {
        p.resize(n, 0);
        r.resize(n, 0);

        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int Find(int x) {
        if (p[x] != x) {
            p[x] = Find(p[x]);
        }
        return p[x];
    }

    void Union(int x, int y) {
        int px = Find(x);
        int py = Find(y);
        if (px == py) {
            return;
        }

        if (r[px] > r[py]) {
            p[py] = px;
        } else if (r[py] > r[px]) {
            p[px] = py;
        } else {
            p[py] = px;
            r[px]++;
        }
    }
};
class Solution {
public:
    void find_factors(int val, vector<int>& v) {
        for (int j = 2; (j * j) <= val; j++) {
            bool add = false;
            while ((val % j) == 0) {
                val = val / j;
                add = true;
            }
            if (add) {
                v.push_back(j);
            }
        }

        if (val > 1) {
            v.push_back(val);
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(n);
        union_find uf(100000);
        unordered_set<int> st;

        if (n == 1) {
            return true;
        }

        // check failed case
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                return false;
            }
            find_factors(nums[i], v[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < v[i].size(); j++) {
                uf.Union(v[i][0], v[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                st.insert(uf.Find(v[i][j]));
            }
        }

        return st.size() == 1;
    }
};
