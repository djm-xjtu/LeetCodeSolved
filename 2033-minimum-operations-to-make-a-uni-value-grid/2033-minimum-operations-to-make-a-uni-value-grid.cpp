class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size() * grid[0].size(), sum = 0;
        vector<int> g;
        for(auto& st : grid){
            for(auto& t : st){
                if((t - grid[0][0]) % x != 0) return -1;
                g.push_back(t);
            }
        }
        sort(g.begin(), g.end());
        for(auto& st : g){
            sum += abs(st - g[n/2]) / x;
        }
        return sum;
    }
};