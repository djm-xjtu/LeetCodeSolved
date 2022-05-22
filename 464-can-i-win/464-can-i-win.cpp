class Solution {
public:
    unordered_map<int, bool> h;
    bool canIWin(int max_val, int target) {
        if(max_val >= target) return true;
        if((max_val + 1) * max_val < target) return false;
        return dfs(max_val, target, 0, 0);
    }
    bool dfs(int max_val, int target, int sum, int used){
        if(h.count(used)) return h[used];
        for(int i = 0; i < max_val; i++){
            int cur = 1 << i;
            if((used & cur) == 0){
                if(sum + i + 1 >= target || !dfs(max_val, target, sum + i + 1, used | cur)){
                    h[used] = true;
                    return true;
                }
            }
        }
        h[used] = false;
        return false;
    }
};