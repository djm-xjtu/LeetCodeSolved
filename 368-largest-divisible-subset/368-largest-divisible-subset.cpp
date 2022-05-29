class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), cnt = 0, p = 0;
        vector<int> f(1010, 1), pre(1010, -1), ans;
        //记录路径和找最大长度要分开
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    f[i] = max(f[i], f[j] + 1);
                    if(f[i] == f[j] + 1)
                    pre[i] = j;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(f[i] > cnt) 
                cnt = f[i], p = i;
        }

        while(p != -1){
            ans.push_back(nums[p]);
            p = pre[p];
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};