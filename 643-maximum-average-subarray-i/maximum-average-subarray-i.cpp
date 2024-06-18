class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0, right = 0;
        double avg = 0, ans = INT_MIN;

        while (right < nums.size()) {
            avg += nums[right];
            if (right - left + 1 == k) {
                ans = max(ans, avg); 
                avg -= nums[left]; 
                left++;          
            }
            right++; 
        }
        return ans/k;
    }
};
