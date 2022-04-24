class Solution {
public:
    int binaryGap(int n) {
        vector<int> a;
        bool f = 0;
        int pre = -1;
        int max_val = 0;
        while(n){
            if((n & 1) && !f) a.push_back(1), pre = a.size() - 1, f = 1;
            else if((n & 1) && f){
                a.push_back(1);
                if(a.size() - 1 - pre > max_val) max_val = a.size() - 1 - pre;
                pre = a.size() - 1;
            }
            else a.push_back(0);
            n >>= 1;
        }
        return max_val;
    }
};