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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* cur = head;
        ListNode* tail = new ListNode();
        int len = 0;
        while(cur != nullptr){
            tail = cur;
            cur = cur->next;
            len++;
        }
        k %= len;
        if(!k) return head;
        ListNode* res = new ListNode();
        res->next = head;
        for(int i = 0; i < len - k; i++){
            res = res->next;
        }
        ListNode* ans = new ListNode();
        ans = res->next;
        res->next = nullptr;
        tail->next = head;
        return ans;
    }
};