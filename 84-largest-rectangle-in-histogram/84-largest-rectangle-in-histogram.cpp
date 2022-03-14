class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> stk;
        int ans = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++){
            while(stk.size() && heights[stk.back()] > heights[i]){
                int cnt = stk.back();
                stk.pop_back();
                int left = stk.back() + 1;
                int right = i - 1;
                ans = max(ans, (right - left + 1)*heights[cnt]);
            }
            stk.push_back(i);
        }
        return ans;
    }
};