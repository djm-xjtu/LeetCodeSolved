class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int a = 0, b = 0;
        int Max = INT_MIN, Min = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] > Max ) Max = nums[i], a = i;
            if(nums[i] < Min) Min = nums[i], b = i;
        }
        int ans = INT_MAX;
        int ans_1 = min(abs(a+1) + abs(n-b), abs(b+1) + abs(n-a));
        int ans_2 = max(a+1, b+1);
        int ans_3 = max(n-a, n-b);
        ans = min(ans_1, ans_2);
        ans = min(ans, ans_3);
        return ans;
    }
};