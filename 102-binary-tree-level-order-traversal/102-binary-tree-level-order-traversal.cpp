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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        int index = -1;
        while(q.size()){
            index++;
            res.resize(index+1);
            int len = q.size();
            while(len--){
                TreeNode* r = q.front(); q.pop();
                res[index].push_back(r->val);
                if(r->left) q.push(r->left);
                if(r->right) q.push(r->right);
            }
        }
        return res;
    }
};