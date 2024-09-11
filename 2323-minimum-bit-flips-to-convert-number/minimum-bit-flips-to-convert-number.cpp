class Solution {
public:
string binary(int s){
    string bi="";
    while(s>0){
        bi=(s%2==0?"0":"1")+bi;
        s/=2;
    }
    return bi;
}
    int minBitFlips(int start, int goal) {
        string a=binary(start);
        string b=binary(goal);
         while (a.size() < b.size()) a = "0" + a;
        while (b.size() < a.size()) b = "0" + b;
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])ans++;
        }
        return ans;
    }
};