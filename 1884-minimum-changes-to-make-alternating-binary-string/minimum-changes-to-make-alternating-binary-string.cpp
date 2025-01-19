class Solution {
public:
    int minOperations(string s) {
        int zeroCount=0;
        int oneCount=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='1')oneCount++;
                else zeroCount++;
            }else{
                if(s[i]=='0')oneCount++;
                else zeroCount++;
            }
        }
        return min(zeroCount,oneCount);
    }
};