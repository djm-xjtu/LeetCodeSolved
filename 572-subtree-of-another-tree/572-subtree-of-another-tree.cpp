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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return 0;
        return issub(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool issub(TreeNode* r, TreeNode* sub){
        if(r == nullptr && sub == nullptr) return 1;
        if(r == nullptr || sub == nullptr) return 0;
        if(r->val == sub->val) return issub(r->left, sub->left) && issub(r->right, sub->right);
        else return 0;
    }
};