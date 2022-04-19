class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last = 0;
        for(int i = 1; i < nums.size(); i++){
            while(last < i && i > last + nums[last]){
                last++;
            }
            if(last == i) return 0;
        }
        return 1;
    }
};