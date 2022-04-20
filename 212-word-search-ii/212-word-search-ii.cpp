class Solution {
public:
    class Node{
        public:
        string s;
        Node* son[26];
        Node(){
            for(int i = 0; i < 26; i++){
                son[i] = nullptr;
            }
        }
    };
    Node* root = new Node();
    void insert(string s){
        Node* p = root;
        for(int i = 0; i < s.size(); i++){
            int t = s[i] - 'a';
            if(p->son[t] == nullptr) p->son[t] = new Node();
            p = p->son[t];
        }
        p->s = s;
    }
    int n, m;
    vector<string> path;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    void dfs(vector<vector<char>>& board, int x, int y, Node* node){
        if(x < 0 || x >= n || y < 0 || y >= m) return;
        char t = board[x][y];
        if(t == '*' || node->son[t-'a'] == nullptr) return;
        node = node->son[t-'a'];
        if(node->s.size()) path.push_back(node->s), node->s = "";
        board[x][y] = '*';
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            dfs(board, nx, ny, node);
        }
        board[x][y] = t;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(), m = board[0].size();
        for(auto word : words) {
            insert(word);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int t = board[i][j] - 'a';
                dfs(board, i, j, root);
            }
        }
        return path;
    }
};