class Solution {
public:
    vector<vector<int>> p;
    string s;
    int ans;
    int dfs(int i){
        int len = 0, Max = 0;
        for(auto st : p[i]){
            len = dfs(st) + 1;
            if(s[st] != s[i]){
                ans = max(ans, Max + len);
                Max = max(Max, len);
            } 
        }
        return Max;
    }
    int longestPath(vector<int>& parent, string ss) {
        int n = parent.size();
        s = ss;
        p.resize(n);
        for(int i = 1; i < n; i++)
            p[parent[i]].push_back(i);
        dfs(0);
        return ans + 1;
    }
};