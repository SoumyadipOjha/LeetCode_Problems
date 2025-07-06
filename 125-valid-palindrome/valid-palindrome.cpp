class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.length())return true;
       int left=0;
       int right=s.length();
       while(left<right){
        if(!isalnum(s[left])){
            left++;
            continue;
        }
        if(!isalnum(s[right])){
            right--;
            continue;
        }
        if(tolower(s[left])!=tolower(s[right]))return false;
        left++;
        right--;
       } 
       return true;
    }
};