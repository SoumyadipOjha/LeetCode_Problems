class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v, ans;
        for (int i = 1; i <=9; i++) {
            int num = i;
            for (int j =i+ 1; j <=9; j++) {
                num = num * 10 + j;
                v.push_back(num);
            }
        }
        sort(v.begin(),v.end());
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= low && v[i] <= high) {
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};