/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> cache;
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        if(cache[root] != 0) return cache[root];
        int val1 = root->val;
        val1 += (root->left != nullptr) ? rob(root->left->left) + rob(root->left->right) : 0;
        val1 += (root->right != nullptr) ? rob(root->right->left) + rob(root->right->right) : 0;
        int val2 = rob(root->left) + rob(root->right);
        int Max = max(val1, val2);
        cache[root] = Max;
        return Max;
    }
};
