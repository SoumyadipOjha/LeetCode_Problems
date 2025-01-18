class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int s=1;
        int e=x;
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            // if(mid* mid==x)return mid;
            if(mid==x/mid)return mid;
            if(mid>x/mid)e=mid-1;
            else{
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
    }
};