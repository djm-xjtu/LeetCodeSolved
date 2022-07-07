class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        //row, col
        int n = mat.size(), m = mat[0].size();
        int x = 0, y = 0;
        //my answer
        vector<int> ans(n*m);
        //direction depended by (x + y) % 2
        for(int i = 0; i < n*m; i++){
            ans[i] = mat[x][y];
            if((x + y) % 2 == 0){
                if(y == m - 1){
                    x++;
                }
                else if(x == 0){
                    y++;
                }
                else{
                    x--;
                    y++;
                }
            }
            else{
                if(x == n - 1){
                    y++;
                }
                else if(y == 0){
                    x++;
                }
                else{
                    x++;
                    y--;
                }
            }
        }
        return ans;
    }
};