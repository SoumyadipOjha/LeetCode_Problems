class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>v;
        for(int i=s.size()-1;i>=0;i--){
            v.push_back(s[i]);
        }
        for(int i=0;i<s.size();i++){
            s[i]=v[i];
        }
    }
};