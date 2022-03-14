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
class Solution {
public:
    int pos, carry;
    int res;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node = nullptr;
        ListNode* h = nullptr;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int a = (l1 != nullptr) ? l1->val : 0, b = (l2 != nullptr) ? l2->val : 0;
            pos = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            if(!node) node = h = new ListNode(pos);
            else{
                node->next = new ListNode(pos);
                node = node->next;
            }
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        return h;
    }
};