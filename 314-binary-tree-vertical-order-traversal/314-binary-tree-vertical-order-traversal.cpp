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
    int ld, rd;
    void dfs(TreeNode* root, int level){
        if(!root) return;
        ld = min(ld, level);
        rd = max(rd, level);
        if(root->left) {
            dfs(root->left, level-1);
        }
        if(root->right){
            dfs(root->right, level+1);
        }
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0);
        vector<vector<int>> res(rd - ld + 1);
        if(!root) return {};
        queue<pair<TreeNode*, int>> q;
        q.push({root, -ld});
        while(q.size()){
            int len = q.size();
            while(len--){
                auto t = q.front(); q.pop();
                res[t.second].push_back(t.first->val);
                if(t.first->left) q.push({t.first->left, t.second-1});
                if(t.first->right) q.push({t.first->right, t.second+1});
            }
        }
        return res;
    }
};