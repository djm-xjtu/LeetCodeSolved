class Solution {
public:
    class Node{
        public:
        Node* son[2];
        Node(){
            son[0] = nullptr;
            son[1] = nullptr;
        }
    };
    Node* root = new Node();
    void insert(int x){
        Node* p = root;
        for(int i = 30; i >= 0; i--){
            int t = (x >> i) & 1;
            if(p->son[t] == nullptr){
                p->son[t] = new Node();
            }
            p = p->son[t];
        }
    }
    int search(int x){
        Node* p = root;
        int res = 0;
        for(int i = 30; i >= 0; i--){
            int t = (x >> i) & 1;
            if(t == 0 && p->son[1]){
                res += (1 << i);
                p = p->son[1];
            }
            else if(t == 1 && p->son[0]){
                res += (1 << i);
                p = p->son[0];
            }
            else p = p->son[t];
        }
        return res;
    }
    int findMaximumXOR(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(auto i : nums) insert(i);
        int res = 0;
        for(auto i : nums) res = max(res, search(i));
        return res;
    }
};