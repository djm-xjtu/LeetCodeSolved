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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* cur = head;
        ListNode* h = head;
        int len = 0;
        while(cur != nullptr){
            stk.push(cur);
            len++;
            cur = cur->next;
        }
        int ret = len / 2;
        if(len % 2){
        for(int i = 0; i < ret; i++){
            ListNode* p = stk.top(); stk.pop();
            ListNode* ne = h->next;
            h->next = p;
            p->next = ne;
            h = ne;
            if(i == ret - 1) ne->next = nullptr;
        }
        }
        else{
            for(int i = 0; i < ret; i++){
                ListNode* p = stk.top(); stk.pop();
                ListNode* ne = h->next;
                h->next = p;
                p->next = ne;
                h = ne;
                if(i == ret - 1) p->next = nullptr;
            }
        }
    }
};