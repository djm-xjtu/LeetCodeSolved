#define GetState(x, n) (x & (1 << n))
#define SetState(x, n) (x | (1 << n))
class Solution {
public:
    int side, cnt, n;
    vector<int> d;
    bool dfs(vector<int>& nums, int sum, int state){
        bool ans = 0;
        if(d[state] != -1) return d[state];
        for(int i = 0; i < n; i++){
            if(!GetState(state, i) && sum + nums[i] <= side){
                int new_sum = (sum + nums[i]) % side;
                if(dfs(nums, new_sum, SetState(state, i))){
                    ans = 1;
                    break;
                }
            }
        }
        //bool记忆化
        //记忆从某个状态到达不了终点
        d[state] = ans;
        return ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        cnt = accumulate(nums.begin(), nums.end(), 0);
        if(cnt % k) return false;
        side = cnt / k;
        d.resize(1 << n, -1);
        d[(1 << n) - 1] = 1;
        return dfs(nums, 0, 0);
    }
};