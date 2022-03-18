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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        if(root == nullptr) return res;
        TreeNode* r = root;
        while(r != nullptr || stk.size()){
            while(r != nullptr){
                stk.push(r);
                r = r->left;
            }
            TreeNode* t = stk.top(); stk.pop();
            res.push_back(t->val);
            r = t->right;
        }
        return res;
    }
};