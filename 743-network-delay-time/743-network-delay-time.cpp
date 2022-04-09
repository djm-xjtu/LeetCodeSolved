const int N = 6010;
class Solution {
public:
    int e[N], w[N], ne[N], h[N], idx;
    int d[N], n, k;
    bool vis[N];
    void add(int x, int y, int z){
        e[++idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx;
    }
    int dijkstra(){
        memset(d, 0x3f, sizeof d);
        priority_queue<pair<int, int>> q;
        d[k] = 0;
        q.push({0, k});
        while(q.size()){
            int x = q.top().second; q.pop();
            if(vis[x]) continue;
            vis[x] = 1;
            for(int i = h[x]; i; i = ne[i]){
                int y = e[i], z = w[i];
                if(d[y] > d[x] + z){
                    d[y] = d[x] + z;
                    q.push({-d[y], y});
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            res = max(res, d[i]);
        }
        if(res == 0x3f3f3f3f) return -1;
        return res;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto i : times){
            add(i[0], i[1], i[2]);
        }
        this->n = n;
        this->k = k;
        return dijkstra();
    }
};