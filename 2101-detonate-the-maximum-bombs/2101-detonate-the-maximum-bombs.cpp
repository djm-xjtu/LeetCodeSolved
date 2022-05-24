typedef long long ll;
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), ans = 0;
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    ll x = abs(bombs[i][0] - bombs[j][0]);
                    ll y = abs(bombs[i][1] - bombs[j][1]);
                    ll distance = x*x + y*y;
                    if(distance <= 1ll*bombs[i][2] * bombs[i][2]) g[i].push_back(j);
                }
            }
        }
        for(int i = 0; i < n; i++){
            queue<int> q;
            q.push(i);
            vector<bool> vis(n, 0);
            vis[i] = 1;
            int cnt = 0;
            while(q.size()){
                auto t = q.front();
                cnt++;
                q.pop();
                for(auto st : g[t]){
                    if(!vis[st]){
                        vis[st] = 1;
                        q.push(st);
                    }
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};