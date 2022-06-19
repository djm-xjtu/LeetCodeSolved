class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        int f[n][m]; //不含本位置消耗，到达目标点的消耗最小量
        memset(f, INT_MIN, sizeof f);
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(i == n - 1 && j == m - 1){
                    f[i][j] = 1;
                }
                else if(i == n - 1){
                    f[i][j] = f[i][j+1] - dungeon[i][j+1];
                }
                else if(j == m - 1){
                    f[i][j] = f[i+1][j] - dungeon[i+1][j];
                }
                else{
                    f[i][j] = min(f[i][j+1] - dungeon[i][j+1], f[i+1][j] - dungeon[i+1][j]);
                }
                f[i][j] = max(f[i][j], 1);
            }
        }
        f[0][0] = f[0][0] - dungeon[0][0];
        f[0][0] = max(f[0][0], 1);
        return f[0][0];
    }
};