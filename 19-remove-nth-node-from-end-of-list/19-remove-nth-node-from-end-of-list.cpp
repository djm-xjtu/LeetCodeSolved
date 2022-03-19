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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* l = new ListNode();
        ListNode* r = new ListNode();
        l->next = head;
        r->next = head;
        ListNode* dummy = l;
        for(int i = 0; i <= n; i++) r = r->next;
        while(r != nullptr){
            r = r->next;
            l = l->next;
        }
        if(l->next != nullptr) l->next = l->next->next;
        else l->next = nullptr;
        return dummy->next;
    }
};