class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int n = height.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(stk.size() && height[stk.top()] < height[i]){
                int cnt = stk.top(); stk.pop();
                if(stk.empty()) break;
                int l = stk.top();
                int r = i;
                int len = r - l - 1;
                int h = min(height[l], height[r]) - height[cnt];
                ans += h * len;
            }
            stk.push(i);
        }
        return ans;
    }
};