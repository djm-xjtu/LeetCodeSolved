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
    string p, q, path;
    void dfs(TreeNode* root, int target1, int target2){
        if(root->val == target1) p = path;
        if(root->val == target2) q = path;
        if(root->left) path += "L", dfs(root->left, target1, target2), path.pop_back();
        if(root->right) path += "R", dfs(root->right, target1, target2), path.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        dfs(root, startValue, destValue);
        int i = 0, j = 0;
        while(p[i] == q[j]) i++, j++;
        return string(p.size() - i, 'U') + q.substr(j);
    }
};