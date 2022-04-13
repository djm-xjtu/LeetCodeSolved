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
    vector<int> ans;
    int res = 1e9;
    TreeNode* pre;
    void inorder(TreeNode* r){
        if(r == nullptr) return;
        inorder(r->left);
        if(pre) res = min(res, abs(r->val - pre->val));
        pre = r;
        inorder(r->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return res;
    }
};