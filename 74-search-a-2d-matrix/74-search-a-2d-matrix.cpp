class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(matrix[mid / m][mid % m] < target) l = mid + 1;
            else r = mid;
        }
        return matrix[l / m][l % m] == target;
    }
};