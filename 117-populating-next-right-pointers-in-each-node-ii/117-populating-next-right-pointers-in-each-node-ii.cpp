/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        Node* dummy = new Node();
        dummy->next = root;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            int len = q.size()-1;
            while(len--){
                Node* t = q.front(); q.pop();
                t->next = q.front();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            Node* a = q.front(); q.pop();
            a->next = NULL;
            if(a->left) q.push(a->left);
            if(a->right) q.push(a->right);
        }
        return dummy->next;
    }
};