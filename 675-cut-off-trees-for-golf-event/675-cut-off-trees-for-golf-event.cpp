class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    int bfs(vector<vector<int>>& forest, pair<int, int> st, pair<int, int> ed){
        int n = forest.size(), m = forest[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pair<int, int>> q;
        q.push(st);
        int step = 0;
        while(q.size()){
            int len = q.size();
            step++;
            while(len--){
                auto t = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = t.first + dx[i], ny = t.second + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(forest[nx][ny] == 0 || vis[nx][ny]) continue;
                    if(nx == ed.first && ny == ed.second) return step;
                    vis[nx][ny] = 1;
                    q.emplace(nx, ny);
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int ans = 0;
        int n = forest.size(), m = forest[0].size();
        priority_queue<int, vector<int>, greater<int>> st;
        unordered_map<int, pair<int, int>> h;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(forest[i][j] >= 2){
                    st.push(forest[i][j]);
                    h[forest[i][j]] = {i, j};
                }
            }
        }
        pair<int, int> pre = {0, 0};
        if(forest[0][0] == 0) return -1;
        if(st.top() == forest[0][0]) st.pop();
        forest[0][0] = 1;
        while(st.size()){
            int target = st.top();
            st.pop();
            auto pos = h[target];
            int step = bfs(forest, pre, pos);
            //cout << step;
            if(step == -1) return -1;
            ans += step;
            pre = pos;
            forest[pos.first][pos.second] = 1;
        }
        return ans;
    }
};