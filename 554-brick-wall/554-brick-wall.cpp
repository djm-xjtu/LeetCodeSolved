class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> h;
        int ans = 0;
        int width = accumulate(wall[0].begin(), wall[0].end(), 0);
        for(auto i : wall){
            int s = 0;
            for(auto j : i){
                s += j;
                h[s]++;
            }
        }
        for(auto i : h){
            if(i.first != width && i.first != 0)
                ans = max(ans, i.second);
        }
        return wall.size() - ans;
    }
};