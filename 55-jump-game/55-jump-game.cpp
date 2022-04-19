class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last = 0;
        for(int i = 1; i < nums.size(); i++){
            while(last < i && last + nums[last] < i) last++; //枚举每个点的最远跳法
            if(last == i) return 0; // i前所有点都挑不到i
        }
        return 1;
    }
};