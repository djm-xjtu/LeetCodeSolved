class Solution {
public:
    int e[200010], ne[200010], h[100010], idx;
    int d[100010];
    void add(int x, int y){
        e[++idx] = y, ne[idx] = h[x], h[x] = idx;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto i : prerequisites){
            add(i[1], i[0]);
            d[i[0]]++;
        }
        return topsort(numCourses);
    }
    bool topsort(int num){
        queue<int> q;
        vector<int> p;
        for(int i = 0; i < num; i++){
            if(d[i] == 0) q.push(i);
        }
        while(q.size()){
            auto t = q.front(); q.pop();
            p.push_back(t);
            for(int i = h[t]; i; i = ne[i]){
                int y = e[i];
                d[y]--;
                if(d[y] == 0) q.push(y);
            }
        }
        return p.size() == num;
    }
};