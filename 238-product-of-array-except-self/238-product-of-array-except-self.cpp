class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), l = 1, r = 1;
        vector<int> res(n, 1);
        //l记录除了当前数外左边的累乘
        //r记录除了当前数外右边的累乘
        for(int i = 0; i < n; i++){
            res[i] *= l;
            l *= nums[i];

            res[n - i - 1] *= r;
            r *= nums[n - i - 1];
        }
        return res;
    }
};