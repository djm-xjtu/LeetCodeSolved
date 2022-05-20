class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ']'){
                stk.push(s[i]);
                continue;
            }
            string cnt = "";
            string str = "";
            while(stk.top() != '['){
                char a = stk.top();
                stk.pop();
                str += a;
            }
            reverse(str.begin(), str.end());
            stk.pop();
            while(stk.size() && stk.top() >= '0' && stk.top() <= '9'){
                cnt += stk.top();
                stk.pop();
            }
            reverse(cnt.begin(), cnt.end());
            int count = stoi(cnt);
            while(count--){
                for(int j = 0; j < str.size(); j++){
                    stk.push(str[j]);
                }
            }
        }
        while(stk.size()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};