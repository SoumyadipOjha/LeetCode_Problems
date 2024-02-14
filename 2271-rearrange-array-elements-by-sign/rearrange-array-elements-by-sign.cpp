class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> n;

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                p.push_back(nums[i]);
            } else {
                n.push_back(nums[i]);
            }
        }
        int pIndex = 0;
        int nIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                ans.push_back(p[pIndex++]); 
            } else {
                ans.push_back(n[nIndex++]); 
            }
        }
        return ans;
    }
};