class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> g;
        for(auto st : grid)
            for(auto t : st)
                g.push_back(t);
        sort(g.begin(), g.end());
        //保证每个数整除x一致
        int k = g[0] % x, sum = 0;
        int n = g.size();
        for(int i = 0; i < n; i++){
            if(g[i] % x != k) return -1;
            //和前面类似的题一样采取到达中点的贪心思想
            //前面题已经得到结论，odd and even是一样的
            if(n - 1 - i > i){
                sum += (g[n - i - 1] - g[i]) / x;
            }
        }
        return sum;
    }
};