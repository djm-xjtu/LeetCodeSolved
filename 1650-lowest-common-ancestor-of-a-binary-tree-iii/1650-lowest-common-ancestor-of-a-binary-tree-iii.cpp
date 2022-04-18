/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    vector<Node*> a;
    Node* lowestCommonAncestor(Node* p, Node * q) {
        while(p != nullptr){
            a.push_back(p);
            p = p->parent;
        }
        while(q != nullptr){
            for(auto i : a){
                if(i->val == q->val) return i;
            }
            q = q->parent;
        }
        return nullptr;
    }
};