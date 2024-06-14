class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ss = s.size();
        int ts = t.size();
        int sp = 0, tp = 0;
        while (tp < ts && sp<ss) {
            if (s[sp] == t[tp]){
                sp++;tp++;}
                else{
                    tp++;
                }
        }
        return sp == s.size();
    }
};