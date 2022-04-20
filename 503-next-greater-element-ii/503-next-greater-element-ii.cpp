class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        unordered_map<int, int> h;
        int len = nums.size();
        for(int i = 0; i < len; i++) nums.push_back(nums[i]);
        for(int i = 0; i < nums.size(); i++){
            while(!stk.empty() && nums[stk.top()] < nums[i]){
                int t = stk.top(); stk.pop();
                h[t] = nums[i];
            }
            stk.push(i);
        }
        vector<int> res;
        for(int i = 0; i < len; i++){
            if(h.count(i)) res.push_back(h[i]);
            else res.push_back(-1);
        }
        return res;
    }
};