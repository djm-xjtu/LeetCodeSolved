typedef long long ll;
const int N = 210, M = N * N;
const int mod = 1e9 + 7;
typedef pair<long long, int> pii;
class Solution {
public:
    int e[M], ne[M], h[N], idx;
    ll f[N], d[N], w[M];
    bool vis[N];
    void add(int a, int b, int c){
        e[++idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
    }
    void dijkstra(){
        memset(d, 0x3f, sizeof d);
        priority_queue<pii, vector<pii>, greater<pii>> q;
        //len : 0, start : 0
        q.push({0, 0});
        d[0] = 0;
        f[0] = 1;
        while(q.size()){
            auto x = q.top().second;
            q.pop();
            if(vis[x]) continue;
            vis[x] = 1;
            for(int i = h[x]; i; i = ne[i]){
                int y = e[i], z = w[i];
                if(d[y] > d[x] + z){
                    d[y] = d[x] + z;
                    f[y] = f[x];
                    q.push({d[y], y});
                }
                else if(d[y] == d[x] + z){
                    f[y] = (f[x] + f[y]) % mod;
                }
            }
        }
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        for(auto i : roads){
            add(i[0], i[1], i[2]);
            add(i[1], i[0], i[2]);
        }
        dijkstra();
        return f[n-1];
    }
};