class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int maxi = 0;
        while (left < right) {
            ans = min(height[left], height[right]) * (right - left);
            maxi = max(maxi, ans);
            if (height[left] < height[right]) {
                left++;
            } else {

                right--;
            }
        }
        return maxi;
    }
};