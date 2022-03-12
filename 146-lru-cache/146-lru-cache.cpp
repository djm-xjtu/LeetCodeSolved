struct LinkedList{
    int key, value;
    LinkedList* pre;
    LinkedList* next;
    LinkedList(): key(0), value(0), pre(nullptr), next(nullptr){}
    LinkedList(int _key, int _value): key(_key), value(_value), pre(nullptr), next(nullptr){}
};
class LRUCache {
private:
    unordered_map<int, LinkedList*> cache;
    LinkedList* head;
    LinkedList* tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new LinkedList();
        tail = new LinkedList();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        LinkedList* node = cache[key];
        movetoHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            LinkedList* node = cache[key];
            node->value = value;
            movetoHead(node);
        }
        else{
            LinkedList* node = new LinkedList(key, value);
            cache[key] = node;
            addToHead(node); 
            size++;
            if(size > capacity){
                LinkedList* t = removeTail();
                cache.erase(t->key);
                delete t;
                size--;
            }
        }
    }
    
    void addToHead(LinkedList* node){
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }
        
    void movetoHead(LinkedList* node){
        removeNode(node);
        addToHead(node);
    }
    
    void removeNode(LinkedList* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    LinkedList* removeTail(){
        LinkedList* node = tail->pre;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */