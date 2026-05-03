class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int cnt = 0;
        while (cnt < n) {
            if (s == goal)
                return true;
            char c = s[0];
            s.erase(s.begin());
            s.push_back(c);
            cnt++;
        }
        return false;
    }
};