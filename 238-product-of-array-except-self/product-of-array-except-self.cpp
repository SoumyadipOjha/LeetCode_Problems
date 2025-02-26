class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        // calculate suffix multiplications
        vector<int>suf(n,1);
        suf[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            suf[i]=suf[i-1]*nums[i];
        }
        // calculate prefix multiplications
        vector<int>pre(n,1);
        pre[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            pre[i]=pre[i+1]*nums[i];
        }

        // store in an answer array
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            int leftMul=(i>0)?suf[i-1]:1;
            int rightMul=(i<n-1)?pre[i+1]:1;
            ans[i]=leftMul*rightMul;
        }
        return ans;
    }
};