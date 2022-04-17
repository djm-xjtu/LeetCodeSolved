class Solution {
public:
    bool is_prime(int x){
        if(x <= 1) return 0;
        for(int i = 2; i <= x / i; i++){
            if(x % i == 0) return 0;
        }
        return 1;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; i++){
            int t = i;
            int k = 0;
            while(t){
                t -= (t & (-t));
                k++;
            }
            if(is_prime(k)) cnt++;
        }
        return cnt;
    }
};