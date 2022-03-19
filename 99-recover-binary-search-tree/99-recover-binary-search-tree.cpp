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
    TreeNode* pre;
    TreeNode* l;
    TreeNode* r;
    void inorder(TreeNode* ro){
        if(ro == nullptr) return;
        inorder(ro->left);
        if(pre != nullptr && ro->val < pre->val){
            if(l == nullptr) l = pre;
            r = ro;
        }
        pre = ro;
        inorder(ro->right);
    }
    void recoverTree(TreeNode* root) {
        //only two nodes swapped
        inorder(root);
        int t = l->val;
        l->val = r->val;
        r->val = t;
    }
};