class Solution {
public:
    int jump(vector<int>& nums) {
        int last = 0;
        int f[nums.size()];
        memset(f, 0, sizeof f);
        for(int i = 1; i < nums.size(); i++){
            int t = last;
            while(last < i && last + nums[last] < i) last++;
            //因为此时i只比last的极限距离多一格，而因为终点一定可达，所以每个格子至少是1，因此一定可以在nums[last]+last范围内找到一个点可达i
            f[i] = f[last] + 1;
        }
        return f[nums.size()-1];
    }
};