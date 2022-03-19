/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* cur, TreeNode* des, vector<TreeNode*>& res){
        if(cur == nullptr) return 0;
        if(cur == des) {
            res.push_back(cur);
            return 1;
        }
        if(dfs(cur->left, des, res) == 1 || dfs(cur->right, des, res) == 1){
            res.push_back(cur);
            return 1;
        }
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //dfs : 一般的二叉树怎么找到一个节点的路径
        vector<TreeNode*> path_p, path_q;
        dfs(root, p, path_p);
        dfs(root, q, path_q);
        int Min = min(path_q.size(), path_p.size());
        reverse(path_p.begin(), path_p.end());
        reverse(path_q.begin(), path_q.end());
        for(int i = Min-1; i >= 0; i--){
            if(path_p[i]->val == path_q[i]->val) return path_p[i];
        }
        return nullptr;
    }
};