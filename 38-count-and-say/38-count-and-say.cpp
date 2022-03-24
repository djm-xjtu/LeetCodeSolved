class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if(n == 1) return res;
        for(int i = 2; i <= n; i++){
            int m = res.size();
            string s = "";
            for(int j = 0; j < m; j++){
                int k = j;
                while(j + 1 < m && res[j] == res[j+1]) j++;
                string t = to_string(j - k + 1) + res[j];
                s += t;
            }
            res = s;
        }
        return res;
    }
};