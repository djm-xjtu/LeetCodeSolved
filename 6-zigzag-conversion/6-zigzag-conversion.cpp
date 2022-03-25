class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1) return s;
        vector<string> str(numRows);
        string ans = "";
        int i = 0, f = -1;
        for(int j = 0; j < n; j++){
            str[i].push_back(s[j]);
            if(i == 0 || i == numRows - 1) f = -f;
            i += f;
        }
        for(string t : str){
            ans += t;
        }
        
        return ans;
    }
};