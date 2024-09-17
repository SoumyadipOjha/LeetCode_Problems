class Solution {
public:


    vector<string> uncommonFromSentences(string s1, string s2) {
        string a=s1+" "+s2;
        vector<string> words;
        stringstream ss(a);
        string word;
            while (ss >> word) {
                words.push_back(word);
            }
            unordered_map<string,int>map;
            for(auto i:words)map[i]++;
            vector<string>ans;
            for(auto i:map){
                if(i.second==1) ans.push_back(i.first);
            }
            return ans;
    }
};