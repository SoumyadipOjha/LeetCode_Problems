#include <vector>
#include <algorithm>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> v;
        for (int i = 0; i < arr.size(); i++) {
            int count = 1;
            while (i < arr.size() - 1 && arr[i] == arr[i + 1]) {
                count++;
                i++;
            }

            v.push_back(count);
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] == v[i + 1]) {
                return false;
            }
        }

        return true;
    }
};
