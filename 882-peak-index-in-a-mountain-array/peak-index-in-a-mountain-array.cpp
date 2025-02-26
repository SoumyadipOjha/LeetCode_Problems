class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int idx=0;
        int max=INT_MIN;
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1] && arr[i]>max){
                max=arr[i];
                idx=i;
            }
        }
        return idx;
    }
};