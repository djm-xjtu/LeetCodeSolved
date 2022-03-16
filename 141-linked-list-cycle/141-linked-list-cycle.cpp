/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return 0;
        ListNode* l = head;
        ListNode* r = head->next;
        while(l != nullptr && l->next != nullptr && r != nullptr && r->next != nullptr){
            if(l == r) return 1;
            l = l->next;
            r = r->next->next;
        }
        return 0;
    }
};