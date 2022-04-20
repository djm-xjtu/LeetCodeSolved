class Solution {
public:
    //字典树优化DFS
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
    set<string> p;
    bool vis[15][15];
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    void dfs(vector<vector<char>>& board, int x, int y, Node* node){
        if(node->s.size()) p.insert(node->s);
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
            int t = board[nx][ny] - 'a';
            if(node->son[t]){
                vis[nx][ny] = 1;
                dfs(board, nx, ny, node->son[t]);
                vis[nx][ny] = 0;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(), m = board[0].size();
        for(auto word : words) {
            insert(word);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int t = board[i][j] - 'a';
                if(root->son[t]){
                    vis[i][j] = 1;
                    dfs(board, i, j, root->son[t]);
                    vis[i][j] = 0;
                }
            }
        }
        for(auto i : p) path.push_back(i);
        return path;
    }
};