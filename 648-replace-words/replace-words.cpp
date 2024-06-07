class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans = "";
        unordered_map<string, int> mp;
        for (auto it : dictionary) {
            mp[it]++;
        }
        string word = "";
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] >= 'a' && sentence[i] <= 'z') {
                word += sentence[i];
            }
            if (mp[word] > 0) {
                ans += word;
                while (sentence[i] != ' ' && i < sentence.size()) {
                    i++;
                }
                word = "";
            }
            if (sentence[i] == ' ') {
                ans += word + " ";
                word = "";
            }
        }
        if (!word.empty()) {
            ans += word;
        }
        return ans;
    }
};
