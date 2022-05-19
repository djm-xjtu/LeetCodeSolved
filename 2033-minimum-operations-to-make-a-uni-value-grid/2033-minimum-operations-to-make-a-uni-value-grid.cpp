class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> g;
        for(auto st : grid)
            for(auto t : st)
                g.push_back(t);
        sort(g.begin(), g.end());
        int k = g[0] % x, sum = 0;
        int n = g.size();
        for(int i = 0; i < n; i++){
            if(g[i] % x != k) return -1;
            if(n - 1 - i > i){
                sum += (g[n - i - 1] - g[i]) / x;
            }
        }
        return sum;
    }
};