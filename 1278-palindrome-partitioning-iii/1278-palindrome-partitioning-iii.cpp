class Solution {
public:
    int palindromePartition(string s, int cnt) {
        int n = s.size();
        s.insert(0, " ");
        int count[n+1][n+1];
        memset(count, 0, sizeof count);
        //len=2   if len=1 max(i) = n, count[i+1][j-1] overflow and count[i][i] = 0 setted
        for(int len = 2; len <= n; len++){
            for(int i = 1; i <= n - len + 1; i++){
                int j = i + len - 1;
                if(s[i] == s[j])
                //不用写min，原因是len=i一定是由len=i-2层得到的
                    count[i][j] = count[i+1][j-1];
                else
                    count[i][j] = count[i+1][j-1] + 1;
            }
        }
        int f[n+1][cnt+1];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int k = 1; k <= min(i, cnt); k++){
                for(int j = i; j >= k; j--){
                    f[i][k] = min(f[i][k], f[j-1][k-1] + count[j][i]);
                }
            }
        }
        return f[n][cnt];
    }
};