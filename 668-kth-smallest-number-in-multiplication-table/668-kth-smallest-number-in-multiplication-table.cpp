class Solution {
public:
    // count number of element larger than or equal to mid
    int check(int m, int n, int mid){
        int i = m, j = 1;
        int res = 0;
        while(i >= 0 && j <= n){
            if(i * j <= mid){
                res += i;
                j++;
            }
            else i--;
        }
        return res;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while(l < r){
            int mid = l + r >> 1;
            if(check(m, n, mid) >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};