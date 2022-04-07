class MyHashMap {
public:
    int N = 20010;
    vector<pair<int, int>> hash;
    MyHashMap() {
        hash = vector<pair<int, int>>(N, {-1, -1});
    }
    
    int find(int key){
        int t = key % N;
        while(hash[t].first != -1 && hash[t].first != key){
            t = (t + 1) % N;
        }
        return t;
    }
    
    void put(int key, int value) {
        int t = key % N;
        while(hash[t].first != -1 && hash[t].first != key && hash[t].first != -2){
            t = (t + 1) % N;
        }
        hash[t] = {key, value};
    }
    
    int get(int key) {
        int t = find(key);
        return hash[t].second;
    }
    
    void remove(int key) {
        int t = find(key);
        hash[t].first = -2;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */