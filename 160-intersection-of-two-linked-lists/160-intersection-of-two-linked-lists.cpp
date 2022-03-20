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
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        ListNode* a = new ListNode();
        ListNode* b = new ListNode();
        a = l1, b = l2;
        while(a != b){
            if(a) a = a->next;
            else a = l2;
            if(b) b = b->next;
            else b = l1;
        }
        return a;
    }
};