class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int ans=arr[0];
        int maxEnding=arr[0];
        int minEnding=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<0)swap(maxEnding,minEnding);
            maxEnding=max(maxEnding*arr[i],arr[i]);
            minEnding=min(minEnding*arr[i],arr[i]);
            ans=max(ans,maxEnding);
        }
        return ans;
    }
};
