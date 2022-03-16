class Solution {
public:
    int n;
    string findLongestWord(string s, vector<string>& dictionary) {
        string longw = "";
        n = s.size();
        for(string str : dictionary){
            if(str.size() < longw.size() || (str.compare(longw) > 0 && str.size() == longw.size())) continue;
            if(isSub(s, str)) longw = str;
        }
        return longw;
    }
    bool isSub(string s, string t){
        int l = 0, r = 0;
        while(l < s.size() && r < t.size()){
            if(s[l] == t[r]) r++;
            l++;
        }
        return r == t.size();
    }
};