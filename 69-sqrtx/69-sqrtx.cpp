class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l < r){
            int mid = (long long)l + r + 1 >> 1; //奇怪了，l + r + 1不能添加括号 写成（l + r + 1）是错误的
            if(mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return r;
        
        //模版2：找最后一个小于目标的
    }
};