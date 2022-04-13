class Solution {
public:
    int e[2010 * 2010], ne[2010 * 2010], h[2010], d[2010], idx, n;
    vector<int> ans;
    void add(int x, int y){
        e[++idx] = y, ne[idx] = h[x], h[x] = idx;
    }
    void topsort(){
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(d[i] == 0) q.push(i), ans.push_back(i);
        }
        while(q.size()){
            auto t = q.front(); q.pop();
            for(int i = h[t]; i; i = ne[i]){
                int y = e[i];
                d[y]--;
                if(d[y] == 0) q.push(y), ans.push_back(y);
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        for(auto i : prerequisites){
            add(i[1], i[0]);
            d[i[0]]++;
        }
        topsort();
        if(ans.size() != n) ans.clear();
        return ans;
    }
};