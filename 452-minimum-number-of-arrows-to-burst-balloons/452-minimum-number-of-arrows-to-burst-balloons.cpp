class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int ans = 1, end = points[0][1];
        for(int i = 1; i < n; i++){
            if(points[i][0] > end){
                ans++;
                end = points[i][1];
            }
            else if(points[i][1] < end){
                end = points[i][1];
            }
        }
        return ans;
    }
};