// C++ Code
/*
// Definition for a Node.
class Node {
public:
    int val;
        vector<Node*> children;

            Node() {}

                Node(int _val) {
                        val = _val;
                            }

                                Node(int _val, vector<Node*> _children) {
                                        val = _val;
                                                children = _children;
                                                    }
                                                    };
                                                    */

class Solution {
    vector<int> res;
    void postOrder(Node* root) {
        if (!root)
            return;
        for (auto child : root->children) {
            postOrder(child);
            res.push_back(child->val);
        }
    }

public:
    vector<int> postorder(Node* root) {
        if (!root)
            return {};
        postOrder(root);
        res.push_back(root->val);
        return res;
    }
};