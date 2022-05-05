class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int mul = 1;
        if(k <= 1) return 0; 
        for(int i = 0, j = 0; i < n; i++){
            mul *= nums[i];
            while(j < n && mul >= k){
                mul /= nums[j];
                j++;
            }
            cnt += i - j + 1;//以i为结尾的子数组数
        }
        return cnt;
    }
};