class Solution {
public:
    int check(vector<vector<int>>& m, int mid){
        int n = m.size();
        int i = n - 1, j = 0, cnt = 0;
        while(i >= 0 && j < n){
            int t = m[i][j];
            if(t <= mid){
                cnt += i + 1;
                j++;
            }
            else i--;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), max_val = -1e9, min_val = 1e9;
        for(auto i : matrix){
            for(auto j : i) max_val = max(max_val, j), min_val = min(min_val, j);
        }
        int l = min_val, r = max_val;
        while(l < r){
            int mid = l + r >> 1;
            if(check(matrix, mid) >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};