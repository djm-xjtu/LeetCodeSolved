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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) return l1;
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* a = new ListNode();
        ListNode* b = new ListNode();
        ListNode* cur = new ListNode();
        ListNode* dummy = new ListNode();
        dummy->next = cur;
        a = l1;
        b = l2;
        while(a != nullptr && b != nullptr){
            if(a->val <= b->val){
                cur->next = a;
                a = a->next;
                cur = cur->next;
                cur->next = nullptr;
            }
            else{
                cur->next = b;
                b = b->next;
                cur = cur->next;
                cur->next = nullptr;
            }
        }
        if(a != nullptr) cur->next = a;
        if(b != nullptr) cur->next = b;
        return dummy->next->next;
    }
};