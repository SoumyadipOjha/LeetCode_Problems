#include <vector>
#include <unordered_set>

class Solution {
public:
    int maxLength(std::vector<std::string>& arr) {
        int result = 0;
        backtrack(arr, "", 0, result);
        return result;
    }

private:
    void backtrack(const std::vector<std::string>& arr, std::string current, int index, int& result) {
        std::unordered_set<char> charSet(current.begin(), current.end());

        if (charSet.size() == current.size()) {
            result = std::max(result, static_cast<int>(current.size()));
        } else {
            return; // Skip this branch if there are duplicates
        }

        for (int i = index; i < arr.size(); ++i) {
            backtrack(arr, current + arr[i], i + 1, result);
        }
    }
};
