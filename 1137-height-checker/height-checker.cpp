class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int>arr;
        int ans=0;
       for(int i:h){
        arr.push_back(i);
       }
       sort(arr.begin(),arr.end());
       for(int i=0;i<h.size();i++){
        if(h[i]!=arr[i]){
            ans++;
        }
       }
       return ans;
    }
};