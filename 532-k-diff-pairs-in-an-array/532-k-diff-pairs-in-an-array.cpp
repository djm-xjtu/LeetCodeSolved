class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> h;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            h[nums[i]]++;
        }
        for(auto st : h){
            if(k == 0){
                cnt += st.second > 1;
            }
            else{
                cnt += h.count(k + st.first);
            }
        }
        return cnt;
    }
};