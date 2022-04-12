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
        if(cache[root]) return cache[root];
        int val1 = root->val;
        val1 += (root->left == nullptr) ? 0 : rob(root->left->left) + rob(root->left->right);
        val1 += (root->right == nullptr) ? 0 : rob(root->right->left) + rob(root->right->right);
        int val2 = rob(root->left) + rob(root->right);
        int Max = max(val1, val2);
        cache[root] = Max;
        return Max;
    }
};
