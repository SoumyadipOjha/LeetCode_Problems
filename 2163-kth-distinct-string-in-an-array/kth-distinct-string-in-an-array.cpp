class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;

        for (string& str : arr) {
            map[str]++;
        }

        int count = 0;

        for (string& str : arr) {
            if (map[str] == 1) {
                count++;
            }

            if (count == k) {
                return str;
            }
        }

        return "";
    }
};
