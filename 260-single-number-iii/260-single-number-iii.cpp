class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum ^= nums[i];
        }
        // 3^5
        // 011
        // 101
        // 110
        int pos = 0;
        for(int i = 0; i < 32; i++){
            if((sum >> i) & 1) {
                pos = i;
                break;
            }
        }
        int s1 = 0, s2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] >> pos) & 1) s1 ^= nums[i];
            else s2 ^= nums[i];
        }
        return vector<int>{s1, s2};
    }
};