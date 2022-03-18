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
    vector<int> get_val(queue<TreeNode*> a){
        vector<int> res;
        while(a.size()){
            res.push_back(a.front()->val);
            a.pop();
        }
        return res;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        int index = -1;
        while(q.size()){
            int len = q.size();
            res.push_back(get_val(q));
            while(len--){
                TreeNode* r = q.front(); q.pop();
                if(r->left) q.push(r->left);
                if(r->right) q.push(r->right);
            }
        }
        return res;
    }
};