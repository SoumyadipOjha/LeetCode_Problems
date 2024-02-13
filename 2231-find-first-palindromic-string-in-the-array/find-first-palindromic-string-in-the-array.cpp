class Solution {
public:
    string firstPalindrome(vector<string>& words) {
    
        
        int n=words.size();
        for(int i=0;i<n;i++){
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