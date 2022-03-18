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
    bool f = 1;
    bool isBalanced(TreeNode* root){
        isbalanced(root);
        return f;
    }
    int isbalanced(TreeNode* root) {
        if(root == nullptr) return 0;
        int l = isbalanced(root->left);
        int r = isbalanced(root->right);
        if(abs(l-r) > 1) f = 0;
        return max(l, r) + 1;
    }
};