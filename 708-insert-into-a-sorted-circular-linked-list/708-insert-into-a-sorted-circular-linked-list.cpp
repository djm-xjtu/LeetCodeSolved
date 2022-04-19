/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        if(!head) {
            newNode->next = newNode;
            return newNode;
        }

        Node* prev = head;
        Node* curr = head->next;
        while(prev->next != head) {
            if(prev->val <= insertVal && curr->val >= insertVal) {
                break;
            }
            if(prev->val > curr->val && (insertVal > prev->val || insertVal < curr->val)) {
                break;
            }
            prev = prev->next;
            curr = curr->next;
        }
        
        newNode->next = curr;
        prev->next = newNode;

        return head;
    }
};