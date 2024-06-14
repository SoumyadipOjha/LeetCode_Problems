class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        int size=n1+n2;
        string ans="";
        for(int i=0;i<size;i++){
            if(i<n1)
           ans+=word1[i];
           if(i<n2)
           ans+=word2[i];
        }

        return ans;
    }
};