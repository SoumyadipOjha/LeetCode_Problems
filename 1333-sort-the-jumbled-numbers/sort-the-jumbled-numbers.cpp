class Solution {
public:
    static int convert(int x, vector<int>& mapping) {
        if (x == 0)
            return mapping[0]; //  edge case
        int z = 0;
        for (int pow10 = 1; x > 0; pow10 *= 10) {
            auto [q, r] = div(x, 10);
            z += mapping[r] * pow10;
            x = q;
        }
        return z;
    }

    static vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, int> f;
        f.reserve(n);
        for (int i = 0; i < n; i++)
            f[nums[i]] = convert(nums[i], mapping);

        sort(nums.begin(), nums.end(),
             [&](int x, int y) { return f[x] < f[y]; });
        return nums;
    }
};
