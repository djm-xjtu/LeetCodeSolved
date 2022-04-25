/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    bool vis[2010];
    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        unordered_map<int, vector<int>> h;
        unordered_map<int, int> p;
        queue<int> q;
        for(auto worker : employees){
            h[worker->id] = worker->subordinates;
            p[worker->id] = worker->importance;
        }
        q.push(id);
        while(q.size()){
            auto t = q.front(); q.pop();
            sum += p[t];
            for(auto i : h[t]){
                if(vis[i]) continue;
                q.push(i);
                vis[i] = 1;
            }
        }
        return sum;
    }
};