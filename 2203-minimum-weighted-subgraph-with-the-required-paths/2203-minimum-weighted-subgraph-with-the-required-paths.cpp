class Solution {
    typedef pair<long long, int> pli;

    int n;
    vector<vector<int>> e1, e2;
    vector<vector<int>> v1, v2;

    vector<long long> dijkstra(int S, vector<vector<int>> &e, vector<vector<int>> &v) {
        vector<long long> d(n);
        for (int i = 0; i < n; i++) d[i] = -1;
        priority_queue<pli> q;
        q.push(pli(0, S));
        while (!q.empty()) {
            pli p = q.top(); q.pop();
            int sn = p.second;
            long long val = -p.first;
            if (d[sn] >= 0) continue;
            d[sn] = val;
            for (int i = 0; i < e[sn].size(); i++) q.push(pli(-val - v[sn][i], e[sn][i]));
        }
        return d;
    }

public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        this->n = n;
        e1 = e2 = v1 = v2 = vector<vector<int>>(n);
        for (auto &edge : edges) {
            e1[edge[0]].push_back(edge[1]); v1[edge[0]].push_back(edge[2]);
            e2[edge[1]].push_back(edge[0]); v2[edge[1]].push_back(edge[2]);
        }
        vector<long long> d1 = dijkstra(src1, e1, v1);
        vector<long long> d2 = dijkstra(src2, e1, v1);
        vector<long long> d3 = dijkstra(dest, e2, v2);
        long long ans = 1e18;
        for (int i = 0; i < n; i++) if (d1[i] >= 0 && d2[i] >= 0 && d3[i] >= 0) ans = min(ans, d1[i] + d2[i] + d3[i]);
        return ans < 1e18 ? ans : -1;
    }
};