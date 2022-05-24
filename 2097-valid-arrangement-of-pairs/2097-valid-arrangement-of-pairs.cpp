class Solution {
public:
    vector<vector<int>> ans;
    map<int, vector<int>> h;
    map<int, int> deg;
    void dfs(int st){
        vector<int>& g = h[st];
        while(!g.empty()){
            int ed = g.back();
            g.pop_back();
            dfs(ed);
            ans.push_back(vector<int>{st, ed});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        for(int i = 0; i < n; i++){
            h[pairs[i][0]].push_back(pairs[i][1]);
            //入-出
            deg[pairs[i][0]]--, deg[pairs[i][1]]++;
        }
        for(auto i : deg){
            if(i.second == -1) dfs(i.first);
        }
        if(ans.empty()) dfs(deg.begin()->first);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};