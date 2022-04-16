class Solution {
public:
    int mod = 1337;
    int largestPalindrome(int n) {
        //枚举
        if(n == 1) return 9;
        int Max = pow(10, n) - 1;
        // 10 << 2
        // 101000
        // 8 + 32 = 40
        // 表示10*2*2
        for(int i = Max; i >= 0; i--){
            long long num = i, t = i;
            while(t){
                num = num * 10 + t % 10;
                t /= 10;
            }
            for(int j = Max; j >= num / j; j--){
                if(num % j == 0) {
                    return (num + mod) % mod;
                }
            }
        }
        return -1;
    }
};