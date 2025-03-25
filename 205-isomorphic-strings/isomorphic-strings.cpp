class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> mapS, mapT;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];

            // Check if mapping exists and is consistent
            if (mapS.count(c1) && mapS[c1] != c2)
                return false;
            if (mapT.count(c2) && mapT[c2] != c1)
                return false;

            // Create the mapping
            mapS[c1] = c2;
            mapT[c2] = c1;
        }
        return true;
    }
};
