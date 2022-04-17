class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long t = 1;
        if(n < 0) return 0;
        if(t == n) return 1;
        while(t < n){
            t *= 2;
            if(t == n) return 1;
        }
        return 0;
    }
};