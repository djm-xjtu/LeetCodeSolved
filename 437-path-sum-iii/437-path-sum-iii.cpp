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
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        int count = 0;
        count = sum(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
        return count;
    }
    int sum(TreeNode* root, int target){
        if(root == nullptr) return 0;
        int count = 0;
        if(target == root->val) count++;
        count += sum(root->left, target - root->val) + sum(root->right, target - root->val);
        return count;
    }
};