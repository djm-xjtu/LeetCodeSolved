class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        // i = x * y
        // 15 = 3 * 5
        for(int i = 2; i <= sqrt(n); i++){
            //如果可分，把小的数先通过i步找到，再计算另一个需要几步，因为另一个可能还能被更近路径其他推出
            if(n % i == 0) return i + minSteps(n / i);
        }
        //如果一个数不可分为两个数的乘积
        // 13 = 1 * 13
        return n;
    }
};