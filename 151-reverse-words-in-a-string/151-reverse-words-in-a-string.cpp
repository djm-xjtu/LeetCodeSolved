class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            while(i < n && s[i] == ' ') i++;
            if(i == n) break; //这行很重要！！！！
            int j = i;
            while(j < n && s[j] != ' ') j++;
            string t = s.substr(i, j - i) + " ";
            ans.insert(0, t);
            i = j;
        }
        
        ans.pop_back();
        return ans;
        //解法1 见ac代码 21:17 每个单词自己翻转，翻转后放到字符串s的可能的最前面，最后删掉s的非单词部分再总体翻转
        
        //解法2 本代码 每次找到一个单词插入到ans的开头，最后取掉尾空格
        
    }
};