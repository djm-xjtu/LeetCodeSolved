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
    int t = -1e9;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return t;
    }
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int p = root->val;
        if(l > 0) p += l;
        if(r > 0) p += r;
        t = max(t, p);
        p = max(l, r);
        if(p > 0) return p + root->val;
        return root->val;
    }
};