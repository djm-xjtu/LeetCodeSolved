class Solution {
public:
    static bool cmp(string a, string b){
        string c = "", d = "";
        string e = "", f = "";
        for(int i = 0, cnt = 0; i < a.size(); i++){
            if(a[i] == ' '){
                cnt++;
                if(cnt > 1) break;
                if(cnt == 1){
                    c = a.substr(i + 1, a.size() - i - 1);
                    e = a.substr(0, i + 1);
                }
            }
        }
        for(int i = 0, cnt = 0; i < b.size(); i++){
            if(b[i] == ' '){
                cnt++;
                if(cnt > 1) break;
                if(cnt == 1){
                    d = b.substr(i + 1, b.size() - i - 1);
                    f = b.substr(0, i + 1);
                }
            }
        }
        if(c == d) return e < f;
        else return c < d;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> t1, t2;
        vector<string> ans;
        for(auto log : logs){
            for(int i = 0, cnt = 0; i < log.size(); i++){
                if(log[i] == ' '){
                    cnt++;
                    if(cnt > 1) break;
                    if(cnt == 1){
                        if(log[i+1] >= '0' && log[i+1] <= '9') t1.push_back(log);
                        else t2.push_back(log);
                    }
                }
            }
        }
        sort(t2.begin(), t2.end(),cmp);
        for(auto t : t2) ans.push_back(t);
        for(auto t : t1) ans.push_back(t);
        return ans;
    }
};