class Solution {
public:
int reversee(int n){
    int ans=0;
    while(n>0){
        int rem=n%10;
        ans=ans*10+rem;
        n=n/10;
        
    }
    return ans;
    
}
    int mirrorDistance(int n) {
        // int rev=reversee(n);
        // cout<<rev<<" ";
        string a= to_string(n);
        reverse(a.begin(),a.end());
        int rev=stoi(a);
        return abs(rev-n);
        }
};