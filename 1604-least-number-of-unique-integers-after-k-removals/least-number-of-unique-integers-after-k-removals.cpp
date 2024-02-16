class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int el : arr)
            freq[el]++;
        vector<int> freqVector;

        for (auto p : freq)
            freqVector.push_back(p.second);

        sort(freqVector.begin(), freqVector.end());

        int eleRemove = 0;

        for (int i = 0; i < freqVector.size(); i++) {
            eleRemove += freqVector[i];
            if (eleRemove > k)
                return freqVector.size() - i;
        }

        return 0;
    }
};
