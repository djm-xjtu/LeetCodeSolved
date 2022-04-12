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
    void recoverTree(TreeNode* root) {
        dfs(root);
        TreeNode* a = nullptr;
        TreeNode* b = nullptr;
        for(int i = 0; i < t.size() - 1; i++){
            if(t[i]->val > t[i+1]->val){
                b = t[i+1];
                if(a == nullptr) a = t[i];
            }
        }
        swap(a->val, b->val);
    }
};