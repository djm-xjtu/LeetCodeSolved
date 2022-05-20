class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> h(26, 0);
        int cnt = tasks.size();
        int res = 0;
        for(auto st : tasks){
            h[st - 'A'] ++;
        }
        sort(h.begin(), h.end());
        for(int i = 25; i >= 0; i--){
            if(h[i] != h[25]){
                break;
            }
            res++;
        }
        //其他数肯定会被以 A-X-X-A-X-X-A的形式夹在中间，1个A+n个X
        //每个最多的数都会在最后出现1次，因此要在res
        //有可能小于n，比如A-A-B-B, n = 0
        return max((h[25] - 1) * (n + 1) + res, cnt);
    }
};