class Solution {
public:
    string removeDuplicateLetters(string str) {
        stack<char> stk;
        unordered_map<char, int> cache;
        unordered_map<char, int> vis;
        for(char s : str) cache[s]++;
        string ans = "";
        //始终保持栈内每个字符只有一次
        for(char s : str){
            if(vis[s]){
                cache[s]--;
                continue;
            }
            while(!stk.empty() && stk.top() > s && cache[stk.top()] > 1){
                cache[stk.top()]--;
                vis[stk.top()] = 0;
                stk.pop();
            }
            vis[s] = 1;
            stk.push(s);
        }
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};