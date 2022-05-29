class Solution {
public:
    int findRotateSteps(string ring, string key) {
        auto f = vector<vector<int>>(110, vector<int>(110, 11000));
        // f[i][k] : 第i轮，字母的位置
        unordered_map<char, vector<int>> h;
        int n = ring.size(), m = key.size();
        for(int i = 0; i < n; i++)
            h[ring[i]].push_back(i);
        for(int i = 0; i < m; i++){
            if(!i)
                for(auto st : h[key[i]])
                    f[i][st] = min(st, n - st) + 1;

            else{
                for(auto st : h[key[i]])
                    for(auto sst : h[key[i-1]])
                        f[i][st] = min(f[i][st], f[i-1][sst] + min(abs(sst - st), n - abs(sst - st)) + 1);
            }
        }
        int ans = INT_MAX;
        for(auto st : h[key[m-1]])
            ans = min(ans, f[m-1][st]);
        return ans;
    }
};