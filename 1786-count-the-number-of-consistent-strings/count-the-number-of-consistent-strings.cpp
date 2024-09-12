class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> arr(26, -1);

        for (int i = 0; i < allowed.size(); i++) {
            arr[allowed[i] - 'a'] = 1; 
        }

        int ans = 0;

        for (int i = 0; i < words.size(); i++) {
            string a = words[i];
            bool consistent = true;

            for (int j = 0; j < a.size(); j++) {
                if (arr[a[j] - 'a'] ==-1) { 
                    consistent = false;
                    break;
                }
            }

            if (consistent)
                ans++;
        }

        return ans;
    }
};
