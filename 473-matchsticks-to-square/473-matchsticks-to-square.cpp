#define getBit(x, n) ((x >> n) & 1)
#define setBit(x, n) (x | (1 << n))
class Solution {
public:
    vector<int> d;
    long cnt;
    bool dfs(vector<int>& m, int state, int sum){
        bool ans = 0;
        if(d[state] != -1) return d[state];
        for(int i = 0; i < m.size(); i++){
            if(!getBit(state, i) && sum + m[i] <= cnt){
                int new_sum = (sum + m[i]) % cnt;
                if(dfs(m, setBit(state, i), new_sum)){
                    ans = 1;
                    break;
                }
            }
        }
        d[state] = ans;
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        d.resize(1 << n, -1);
        d[(1 << n) - 1] = 1;
        for(int i : matchsticks)
            cnt += i;
        if(cnt % 4) return false;
        cnt /= 4;
        return dfs(matchsticks, 0, 0);
    }
};