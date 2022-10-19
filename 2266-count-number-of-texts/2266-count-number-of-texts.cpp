class Solution {
public:
    int countTexts(string pressedKeys) {
        int mod = 1e9 + 7;
        int n = pressedKeys.size();
        long f[n+1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        pressedKeys = " " + pressedKeys;
        for(int i = 1; i <= n; i++){
            f[i] = f[i-1];
            auto idx = pressedKeys[i];
            if(i - 2 >= 0 && pressedKeys[i-1] == pressedKeys[i]){
                f[i] = (f[i] + f[i-2]) % mod;
            }
            if(i - 3 >= 0 && pressedKeys[i-2] == pressedKeys[i-1] && pressedKeys[i-1] == pressedKeys[i]){
                f[i] = (f[i] + f[i-3]) % mod;
            }
            if(i - 4 >= 0 && pressedKeys[i-3] == pressedKeys[i-2] && pressedKeys[i-2] == pressedKeys[i-1] && pressedKeys[i-1] == pressedKeys[i] 
              && (idx == '7' || idx == '9')) {
                f[i] = (f[i] + f[i-4]) % mod;
            }
        }
        return f[n];
    }
};