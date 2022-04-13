/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(!head->next) return new TreeNode(head->val);
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* before_slow = new ListNode();
        before_slow->next = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            before_slow = before_slow->next;
        }
        TreeNode* r = new TreeNode(slow->val);
        before_slow->next = nullptr;
        r->left = sortedListToBST(head);
        r->right = sortedListToBST(slow->next);
        return r;
    }
};