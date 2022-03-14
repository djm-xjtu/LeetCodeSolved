class Solution {
public:
    //背公式就好。。
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int t = 0;
        for(int i = 0; i < n/2; i++){
            for(int j = i; j < n - i - 1; j ++){
                t = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = t;
            }
        }
    }
};