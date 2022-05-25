class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        int m = edges.size();
        vector<int> deg(n);
        vector<vector<int>> ma(n);
        for(int i = 0; i < m; i++){
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
            ma[edges[i][0]].push_back(edges[i][1]);
            ma[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(deg[i] == 1) q.push(i), deg[i]--;
        }
        while(q.size()){
            int len = q.size();
            vector<int> res;
            while(len--){
                auto t = q.front();
                res.push_back(t);
                q.pop();
                vector<int> g = ma[t];
                for(auto st : g){
                    deg[st]--;
                    if(deg[st] == 1) q.push(st);
                }
            }
            if(q.size() == 0) return res;
        }
        return {};
    }
};