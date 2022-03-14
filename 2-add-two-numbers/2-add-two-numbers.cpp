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
        while(l1 != nullptr && l2 != nullptr){
            int a = l1->val, b = l2->val;
            pos = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            if(!node) node = h = new ListNode(pos);
            else{
                node->next = new ListNode(pos);
                node = node->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            if(l1 != nullptr){
                pos = (l1->val + carry) % 10;
                carry = (l1->val + carry) / 10;
                l1 = l1->next;
                node->next = new ListNode(pos);
                node = node->next;
            }
            else if(l2 != nullptr){
                pos = (l2->val + carry) % 10;
                carry = (l2->val + carry) / 10;
                l2 = l2->next;
                node->next = new ListNode(pos);
                node = node->next;
            }
            else{
                node->next = new ListNode(carry);
                node = node->next;
                carry = 0;
            }
        }
        return h;
    }
};