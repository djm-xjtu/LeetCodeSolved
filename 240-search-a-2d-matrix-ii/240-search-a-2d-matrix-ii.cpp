class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;//从最大的一列开始搜，保证走过之前的都是比target小的数
        while(i < n && j >= 0){
            if(matrix[i][j] == target) return 1;
            else if(matrix[i][j] < target) i++; //i, j 以前的都比i，j小
            else j--;
        }
        return 0;
    }
};