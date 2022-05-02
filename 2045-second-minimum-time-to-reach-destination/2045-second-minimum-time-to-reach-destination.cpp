class Solution {
public:
    bool vis1[30000], vis2[30000], vis3[30000], vis4[30000], vis5[30000], vis6[30000], vis7[30000], vis8[30000], vis9[30000], vis10[30000];
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        if(n == 1) return 0;
        int cnt = 0, step = 0, pre = 0;
        vector<vector<int>> path(n + 1);
        for(auto i : edges){
            path[i[0]].push_back(i[1]);
            path[i[1]].push_back(i[0]);
        }
        queue<int> q;
        q.push(1);
        vis1[1] = 1;
        while(q.size()){
            int len = q.size();
            if((step / change) % 2) {
                step = change * (step / change + 1);
            }
            step += time;
            while(len--){
                int t = q.front(); q.pop();
                for(auto i : path[t]){
                    if(i == n){
                        if(cnt == 1 && step > pre) return step;
                        if(cnt == 0) {
                            pre = step;
                            cnt++;
                        }
                        q.push(i);
                    }
                    else{
                        if(vis1[i] && vis2[i] && vis3[i] && vis4[i] && vis5[i] && vis6[i] && vis7[i] && vis8[i] && vis9[i] && vis10[i]) continue;
                        if(vis1[i] == 0) vis1[i] = 1;
                        else if(vis2[i] == 0) vis2[i] = 1;
                        else if(vis3[i] == 0) vis3[i] = 1;
                        else if(vis4[i] == 0) vis4[i] = 1;
                        else if(vis5[i] == 0) vis5[i] = 1;
                        else if(vis6[i] == 0) vis6[i] = 1;
                        else if(vis7[i] == 0) vis7[i] = 1;
                        else if(vis8[i] == 0) vis8[i] = 1;
                        else if(vis9[i] == 0) vis9[i] = 1;
                        else vis10[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
        return -1;
    }
};