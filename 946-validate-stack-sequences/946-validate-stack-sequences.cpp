class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int l = 0, r = 0;
        stack<int> stk;
        while(l < n && r < n){
            stk.push(pushed[l++]);
            int index = r;
            while(stk.size() && index < n && popped[index] == stk.top()){
                stk.pop();
                index++;
            }
            r = index;
        }
        int index = r;
        while(stk.size() && index < n && popped[index] == stk.top()){
            index++;
            stk.pop();
        }
        return stk.empty() && l == n && r == n;
    }
};