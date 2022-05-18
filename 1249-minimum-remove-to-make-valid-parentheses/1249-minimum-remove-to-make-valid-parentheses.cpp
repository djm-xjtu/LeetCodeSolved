class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string str = "";
        int left = 0, right = 0;
        for(auto& ch : s){
            if(ch == ')') right++;
        }
        for(auto& ch : s){
            if(ch >= 'a' && ch <= 'z')
                str += ch;
            else if(ch == '('){
                if(left < right){
                    left++;
                    str += ch;
                }
            }
            else{
                if(left > 0){
                    left--;
                    str += ch;
                }
                right--;
            }
        }
        return str;
    }
};