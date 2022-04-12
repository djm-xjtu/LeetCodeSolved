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
    vector<int> t;
    void dfs(TreeNode* r){
        if(r == nullptr) return;
        dfs(r->left);
        dfs(r->right);
        t.push_back(r->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return t;
    }
};