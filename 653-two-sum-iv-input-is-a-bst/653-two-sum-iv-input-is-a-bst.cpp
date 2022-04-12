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
    vector<int> in;
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        for(int i = 0, j = in.size() - 1; i < j; i++){
            while(j > i && in[i] + in[j] > k) j--;
            if(j == i) break;
            if(in[i] + in[j] == k) return 1;
        }
        return 0;
    }
    
    void inorder(TreeNode* r){
        if(r == nullptr) return;
        inorder(r->left);
        in.push_back(r->val);
        inorder(r->right);
    }
};