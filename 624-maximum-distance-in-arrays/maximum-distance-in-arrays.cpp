class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxD = 0;
        int minElement =
            arrays[0][0]; // initialize first element of the first array
        int maxElement =
            arrays[0].back(); // initialize last element of the first array
        for (int i = 1; i < arrays.size(); i++) {
            auto& currArray = arrays[i];
            // Calculate minimum distance between smallest element and the last
            // element of current array
            int disMin = abs(currArray[0] - maxElement);
            // Calculate maximum distance between largest element and the first
            // element of current array
            int disMax = abs(currArray.back() - minElement);
            maxD = max({maxD, disMin, disMax});
            minElement = min(minElement, currArray[0]);
            maxElement = max(maxElement, currArray.back());
        }
        return maxD;
    }
};
