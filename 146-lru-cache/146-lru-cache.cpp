struct L{
    int key, value;
    L* pre;
    L* next;
    L(): key(0), value(0), pre(nullptr), next(nullptr){}
    L(int _key, int _value): key(_key), value(_value), pre(nullptr), next(nullptr){}
};
class LRUCache {
public:
    unordered_map<int, L*> cache;
    int capacity;
    int size;
    L* head;
    L* tail;
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new L();
        tail = new L();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        L* node = cache[key];
        movetohead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            L* node = new L(key, value);
            addtohead(node);
            cache[key] = node;
            size++;
            if(size > capacity){
                L* t = removetail();
                cache.erase(t->key);
                delete t;
                size--;
            }
        }
        else{
            L* t = cache[key];
            t->value = value;
            movetohead(t);
        }
    }
    
    void movetohead(L* node){
        removenode(node);
        addtohead(node);
    }
    
    void addtohead(L* node){
        node->next = head->next;
        head->next->pre = node;
        node->pre = head;
        head->next = node;
    }
    
    void removenode(L* node){
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }
    
    L* removetail(){
        L* node = tail->pre;
        removenode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */