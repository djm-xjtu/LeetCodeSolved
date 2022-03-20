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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        while(head){
            ListNode* p = dummy;
            ListNode* ne = head->next;
            while(p->next != nullptr && p->next->val <= head->val) p = p->next;
            head->next = p->next;
            p->next = head;
            head = ne;
        }
        return dummy->next;
    }
};