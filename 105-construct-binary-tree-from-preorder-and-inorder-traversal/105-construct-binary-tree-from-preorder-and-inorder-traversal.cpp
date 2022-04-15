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
    unordered_map<int, int> cache;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++){
            cache[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, n-1, 0, n-1);
    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl > pr || il > ir) return nullptr;
        // 0 1 2 3 4
        // 
        int r = cache[preorder[pl]];
        int k = r - il; // 左子树的结点数量
        //前序的第一个是根
        TreeNode* root = new TreeNode(preorder[pl]);
        // 前序取掉根也就是第一个结点，中序取掉k位置的点
        root->left = dfs(preorder, inorder, pl + 1, pl + k, il, il + k - 1);
        root->right = dfs(preorder, inorder, pl + k + 1, pr, il + k + 1, ir);
        return root;
    }
};