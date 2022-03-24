class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ans;
        vector<int> path;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int t = img[i][j];
                int count = 1;
                if(i - 1 >= 0){
                    t += img[i-1][j], count++;
                    if(j - 1 >= 0) t += img[i-1][j-1], count++;
                    if(j + 1 < m) t += img[i-1][j+1], count++;
                }
                if(j - 1 >= 0) t += img[i][j-1], count++;
                if(j + 1 < m) t += img[i][j+1], count++;

                if(i + 1 < n){
                    t += img[i+1][j], count++;
                    if(j - 1 >= 0) t += img[i+1][j-1], count++;
                    if(j + 1 < m) t += img[i+1][j+1], count++;
                }
                path.push_back(t/count);
            }
            ans.push_back(path);
            path.clear();
        }
        return ans;
    }
};