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
    vector<TreeNode*> t;
    void dfs(TreeNode* r){
        if(r == nullptr) return;
        dfs(r->left);
        t.push_back(r);
        dfs(r->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        for(int i = 0; i < t.size(); i++){
            for(int j = t.size()-1; j > i; j--){
                t[i]->val += t[j]->val;
            }
        }
        return root;
    }
};