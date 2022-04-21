class Solution {
public:
    int solve(vector<int> heights){
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> stk;
        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int height = heights[stk.top()]; stk.pop();
                int len = i - stk.top() - 1;
                res = max(res, len * height);
            }
            stk.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans, solve(heights));
        }
        return ans;
    }
};
