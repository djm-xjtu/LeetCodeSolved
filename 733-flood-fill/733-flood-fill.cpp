class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        bool vis[n][m];
        memset(vis, 0, sizeof vis);
        int res = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
        while(q.size()){
            auto t = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nx = t.first + dx[i], ny = t.second + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && image[nx][ny] == res){
                    image[nx][ny] = newColor;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return image;
    }
};