class Solution {
public:
    int countArrangement(int n) {
        int f[1 << n];
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++){
            f[1 << i] = 1;
        }
        for(int s = 1; s < 1 << n; s++){
            int tot = 0;
            for(int j = 0; j < n; j++){
                if(s & (1 << j)) tot++;
            }
            for(int j = 0; j < n; j++){
                if(!(s & (1 << j)) && ((tot + 1) % (j + 1) == 0 || (j + 1) % (tot + 1) == 0))
                    f[s | (1 << j)] += f[s];
            }
        }
        return f[(1 << n) - 1];
    }
};