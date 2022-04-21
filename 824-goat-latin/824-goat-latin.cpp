class Solution {
public:
    string toGoatLatin(string sentence) {
        vector<string> s;
        string t = "";
        unordered_map<char, int> h;
        h['a'] = 1, h['e'] = 1, h['i'] = 1, h['o'] = 1, h['u'] = 1;
        h['A'] = 1, h['E'] = 1, h['I'] = 1, h['O'] = 1, h['U'] = 1;
        for(int i = 0; i < sentence.size(); i++){
            if(sentence[i] == ' '){
                s.push_back(t);
                t.clear();
            }
            else{
                t += sentence[i];
            }
        }
        if(t.size()) s.push_back(t);
        for(int i = 0; i < s.size(); i++){
            string str = s[i];
            if(h.count(str[0])){
                str += "ma";
            }
            else{
                char a = str[0];
                str.erase(0,1);
                str += a;
                str += "ma";
            }
            for(int j = 0; j <= i; j++){
                str += "a";
            }
            s[i] = str;
        }
        string ans = "";
        for(auto i : s) ans += i, ans += " ";
        ans.pop_back();
        return ans;
    }
};