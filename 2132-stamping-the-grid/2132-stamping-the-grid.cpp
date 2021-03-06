class Solution {
public:
    bool possibleToStamp(vector<vector<int>> &grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1)), diff(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = i + stampHeight, y = j + stampWidth;
                // 求[x1, y1] 到 [x2, y2]范围的和
                // sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][x2 - 1]
                // 如果能盖就全盖上
                if (x <= m && y <= n && sum[x][y] - sum[x][j] - sum[i][y] + sum[i][j] == 0) {
                    ++diff[i][j];
                    --diff[i][y];
                    --diff[x][j];
                    ++diff[x][y]; 
                }
            }
        }
        // 从查分数组中恢复原数组
        vector<vector<int>> cnt(m + 1, vector<int>(n + 1));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //也可以用滚动数组: cnt[j+1] - cnt[j] = pre[j+1] - pre[j] + diff[i][j]
                cnt[i + 1][j + 1] = cnt[i + 1][j] + cnt[i][j + 1] - cnt[i][j] + diff[i][j];
                if (cnt[i + 1][j + 1] == 0 && grid[i][j] == 0) {
                    return false;
                }
            }
        }

        return true;
    }
};