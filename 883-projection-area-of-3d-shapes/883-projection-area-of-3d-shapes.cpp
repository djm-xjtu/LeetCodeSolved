class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        vector<int> a;
        vector<int> b;
        int z = 0;
        int p = 0;
        for(int i = 0; i < grid.size(); i++){
            int max_val = 0;
            for(int j = 0; j < grid[i].size(); j++){
                max_val = max(max_val, grid[i][j]);
                if(grid[i][j] != 0) z++;
            }
            if(p < grid[i].size()) p = grid[i].size();
            a.push_back(max_val);
        }
        int idx = 0;
        while(p--){
            int max_val = 0;
            for(int i = 0; i < grid.size(); i++){
                max_val = max(max_val, grid[i][idx]);
            }
            b.push_back(max_val);
            idx++;
        }
        int x = 0;
        int y = 0;
        for(auto i : a) x += i;
        for(auto i : b) y += i;
        return x + y + z;
    }
};