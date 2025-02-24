#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int>& m) {
        vector<int> peaks;
        int n = m.size();

        for (int i = 1; i < n - 1;i++) { 
            if (m[i] > m[i - 1] && m[i] > m[i + 1]) {
                peaks.push_back(i);
            }
        }
        return peaks;
    }
};
