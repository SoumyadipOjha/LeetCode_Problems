#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class AllOne {
public:
    // Map to keep track of the count of each key
    unordered_map<string, int> count;

    // Set to store pairs of (count, key) and maintain the ordering
    set<pair<int, string>> st;

    // Function to increment the count of a given key
    void inc(string key) {
        // Get the current count of the key
        int n = count[key];

        // Remove the (count, key) pair from the set if it's already present
        if (n > 0) {
            st.erase({n, key});
        }

        // Increment the count of the key
        count[key]++;

        // Add the updated (new count, key) pair back into the set
        st.insert({count[key], key});
    }

    // Function to decrement the count of a given key
    void dec(string key) {
        // Get the current count of the key
        int n = count[key];

        // If the key exists and its count is greater than 0
        if (n > 0) {
            // Remove the (count, key) pair from the set
            st.erase({n, key});

            // Decrease the count of the key
            count[key]--;

            // If the count is reduced to zero, erase the key from the count map
            if (count[key] == 0) {
                count.erase(key);
            } else {
                // Otherwise, insert the updated (new count, key) pair into the
                // set
                st.insert({count[key], key});
            }
        }
    }

    // Function to return the key with the maximum count
    string getMaxKey() {
        if (!st.empty()) {
            return st.rbegin()->second; // Return the key with the largest count
        }
        return ""; // Return empty if no key exists
    }

    // Function to return the key with the minimum count
    string getMinKey() {
        if (!st.empty()) {
            return st.begin()->second; // Return the key with the smallest count
        }
        return ""; // Return empty if no key exists
    }
};
