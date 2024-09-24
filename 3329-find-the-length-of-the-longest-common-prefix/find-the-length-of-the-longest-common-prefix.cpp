struct Node {
    bool flag = false;
    Node* list[10] = {NULL};
    void put(Node* new_node, char ch) { list[ch - '0'] = new_node; }
    bool containKey(char ch) { return list[ch - '0'] != NULL; }
    Node* get(char ch) { return list[ch - '0']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};
class Solution {
private:
    Node* root;

public:
    Solution() { root = new Node; }
    void insert(string num) {
        Node* node = root;
        for (auto ch : num) {
            if (!node->containKey(ch)) {
                node->put(new Node, ch);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    void Lcp(string num, int& maxLen) {
        Node* node = root;
        int len = 0;
        for (auto ch : num) {
            if (!node->containKey(ch)) {
                return;
            }
            len += 1;
            maxLen = max(maxLen, len);
            node = node->get(ch);
        }
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // This problem can be solved using the simple trie data structure
        // first convert each integer to string
        for (auto num : arr2) {
            insert(to_string(num));
        }
        int maxLen = 0;
        for (auto num : arr1) {
            Lcp(to_string(num), maxLen);
        }
        return maxLen;
    }
};
