class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool a = 0, b = 0;
        //用matrix的第一行和第一列标记是否可以行列含0
        for(int j = 0; j < m; j++){
            if(matrix[0][j] == 0){
                a = 1;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(matrix[i][0] == 0){
                b = 1;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0) matrix[i][0] = 0, matrix[0][j] = 0;
            }
        }
        //要从1开始，不然优先把第一行的数据改了就破坏了后面的数据修改
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if(a) for(int j = 0; j < m; j++) matrix[0][j] = 0;
        if(b) for(int i = 0; i < n; i++) matrix[i][0] = 0;
    }
};