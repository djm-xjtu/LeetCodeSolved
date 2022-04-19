/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        auto t = solve(root);
        t.first->left = t.second;
        t.second->right = t.first;
        return t.first;
    }
    pair<Node*, Node*> solve(Node* root){
        Node* min_node = root;
        Node* max_node = root;
        if(root->left){
            auto left_ret = solve(root->left);
            min_node = left_ret.first;
            left_ret.second->right = root;
            root->left = left_ret.second;
        }
        if(root->right){
            auto right_ret = solve(root->right);
            max_node = right_ret.second;
            right_ret.first->left = root;
            root->right = right_ret.first;
        }
        return {min_node, max_node};
    }
};