class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        // string ans="";
        // for(int i=0;i<words.size();i++){
        //     string temp=words[i];
        //     for(int j=0;j<temp.size()/2;j++){
        //         for(int k=temp.size();k>temp.size()/2;k--){
        //             if(temp[i]==temp[j]){
        //                 ans=temp;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return ans;
        string ans="";
        for(int i=0;i<words.size();i++){
            string temp1=words[i];
            string temp2=words[i];
            reverse(temp1.begin(),temp1.end());
            if(temp1==temp2){
                return temp2;
            }
        }
        return "";
    }
};