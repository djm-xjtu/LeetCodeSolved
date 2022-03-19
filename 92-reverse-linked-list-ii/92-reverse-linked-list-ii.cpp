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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        for(int i = 0; i < left - 1; i++) p = p->next;
        ListNode* a = p->next;
        ListNode* b = a->next;
        for(int i = left+1; i <= right; i++){
            ListNode* c = b->next;
            b->next = a;
            a = b, b = c;
        }
        p->next->next = b;
        p->next = a;
        return dummy->next;
    }
};