class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int bit = 0; bit < 32; bit++){
            int cnt = 0;
            int num = 0;
            for(auto i : nums){
                if((i >> bit) & 1) cnt++, num = i;
            }
            if(cnt % 3 == 1) res += (num & (1 << bit));
        }
        return res;
    }
};