class Solution {
public:
    vector<bool> vis;
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        if(matchsticks.size() < 4) return 0;
        for(int i = 0; i < matchsticks.size(); i++){
            sum += matchsticks[i];
        }
        if(sum % 4) return 0;
        int side = sum / 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vis.resize(matchsticks.size());
        return dfs(matchsticks, 0, side, 0, 0);
    }
    
    bool dfs(vector<int>& matchsticks, int sum, int target, int k, int start){
        if(k == 4) return 1;
        if(sum == target){
            return dfs(matchsticks, 0, target, k+1, 0);
        }
        for(int i = start; i < matchsticks.size(); i++){
            if(sum + matchsticks[i] > target){
                continue;
            }
            
            if(!vis[i]){
                vis[i] = 1;
                if(dfs(matchsticks, sum + matchsticks[i], target, k, i + 1))
                    return 1;
                vis[i] = 0;
                if(sum == 0) return 0;
                if(sum + matchsticks[i] == target) return 0;
            }
        }
        return 0;
    }
};