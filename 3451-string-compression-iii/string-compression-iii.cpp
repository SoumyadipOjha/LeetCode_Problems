class Solution {
public:
    string compressedString(string word) {
      string ans="";
      int i=0;
      while(i<word.size()){
        char temp=word[i];
        int count=0;
        while(i<word.size() && word[i]==temp && count<9){
            count++;
            i++;
        }
        ans+=to_string(count)+temp;
      }  
      return ans;
    }
};