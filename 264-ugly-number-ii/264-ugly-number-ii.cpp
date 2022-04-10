class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0;
        int dp[n+1];
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            int n2 = 2 * dp[a], n3 = 3 * dp[b], n5 = 5 * dp[c];
            int res = min(n2, min(n3, n5));
            if(res == n2) a++;
            if(res == n3) b++;
            if(res == n5) c++;
            dp[i] = res;
        }
        return dp[n-1];
    }
};