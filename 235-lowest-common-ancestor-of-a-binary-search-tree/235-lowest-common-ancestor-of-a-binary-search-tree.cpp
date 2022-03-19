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
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        while (1) {
            if(p->val < r->val && q->val < r->val) r = r->left;
            else if(p->val > r->val && q->val > r->val) r = r->right;
            else break;
        }
        return r;
    }
};
