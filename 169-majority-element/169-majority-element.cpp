class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], cnt = 1;
        //摩尔投票法
        //因为元素出现次数大于一半数量，最后总能拿到该元素
        for(int i = 1; i < nums.size(); i++){
            if(res == nums[i]){
                cnt++;
            }
            else cnt--;
            if(cnt < 0) {
                cnt = 0;
                res = nums[i];
            }
        }
        return res;
    }
};