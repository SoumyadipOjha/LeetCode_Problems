class Solution {
public:
    int maxDistance(vector<int>& colors) {
        //    int ans=0;
        //    for(int i=0;i<colors.size();i++){
        //     for(int j=i+1;j<colors.size();j++){
        //         if(colors[i]!=colors[j]){
        //             ans=max(ans,j-i);
        //         }
        //     }
        //    }
        //     return ans;
        int n=colors.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[n - 1]) {
                ans = max(ans, n - 1 - i);
                break;
            }
        }


        for(int i=n-1;i>=0;i--){
            if(colors[i]!=colors[0]){
                ans=max(ans,i);
                break;
            }
        }
        return ans;
    }
};