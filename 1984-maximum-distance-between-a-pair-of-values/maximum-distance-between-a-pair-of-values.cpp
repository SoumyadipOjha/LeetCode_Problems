class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // int ans = 0;
        // int j = 0;
        // int i=0;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=i;j<nums2.size();j++){
        //         if(nums1[i]<=nums2[j]){
        //             ans=max(ans,j-i);
        //         }
        //     }
        // }
        // return ans;

        int i = 0;
        int j = 0;
        int a = nums1.size();
        int b = nums2.size();
        int ans = 0;
        while (i < a && j < b) {
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++;
            } else {
                i++;
                if (i > j)
                    j = i;
            }
        }
        return ans;
    }
};