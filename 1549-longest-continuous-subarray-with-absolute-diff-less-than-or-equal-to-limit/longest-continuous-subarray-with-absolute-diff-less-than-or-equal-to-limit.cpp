class Solution {
public:
    int longestSubarray(vector<int>& nums, int l) {
        int ans = 0, n = nums.size();
        deque<int> dqmin, dqmax;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {

            while (dqmax.size() && dqmax.back() < nums[i])
                dqmax.pop_back();

            while (dqmin.size() && dqmin.back() > nums[i])
                dqmin.pop_back();

            dqmin.push_back(nums[i]);
            dqmax.push_back(nums[i]);

            int maxi = dqmax.front(), mini = dqmin.front();
            if (maxi - mini <= l)
                ans = max(i - j + 1, ans);
            else {
                if (nums[j] == dqmax.front())
                    dqmax.pop_front();
                if (nums[j] == dqmin.front())
                    dqmin.pop_front();
                j++;
            }
        }
        return ans;
    }
};
