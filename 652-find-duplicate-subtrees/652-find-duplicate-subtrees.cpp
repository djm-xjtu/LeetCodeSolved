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
    vector<TreeNode*> ans;
    unordered_map<string, int> h;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root == nullptr) return ans;
        dfs(root);
        return ans;
    }
    
    string dfs(TreeNode* root){
        if(root == nullptr) return "";
        string s = "";
        s += to_string(root->val) + ",";
        s += dfs(root->left) + ",";
        s += dfs(root->right);
        h[s]++;
        if(h[s] == 2) ans.push_back(root);
        return s;
    }
};