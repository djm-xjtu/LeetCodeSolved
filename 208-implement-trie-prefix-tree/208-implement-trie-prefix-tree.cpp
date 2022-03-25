class Node{
public:
    Node* Next[26];
    bool end;
    Node(){
        memset(Next, NULL, sizeof(Next));
        end = 0;
    }
};

class Trie {
public:
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    ~Trie(){
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* u = q.front(); q.pop();
            for(int i = 0; i < 26; i++){
                if(u->Next[i]) q.push(u->Next[i]);
            }
            delete u;
        }
    }
    
    void insert(string word) {
        Node* node = root;
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(node->Next[word[i] - 'a'] == NULL) node->Next[word[i] - 'a'] = new Node();
            node = node->Next[word[i] - 'a'];
        }
        node->end = 1;
    }
    
    bool search(string word) {
        Node* node = root;
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(node->Next[word[i] - 'a'] == NULL) return 0;
            node = node->Next[word[i] - 'a'];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* node = root;
        for(int i = 0; i < n; i++){
            if(node->Next[prefix[i] - 'a'] == NULL) return 0;
            node = node->Next[prefix[i] - 'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */