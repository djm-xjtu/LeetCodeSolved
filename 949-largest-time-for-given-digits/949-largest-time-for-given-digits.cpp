class Solution {
public:
    bool vis[10];
    string res = "";
    void dfs(vector<int>& arr, string t, int n){
        if(n == 4){
            if(t.substr(0, 2) <= "23" && t.substr(2, 2) <= "59" && t > res){
                res = t;
            }
            return;
        }
        for(int i = 0; i < 4; i++){
            if(vis[i]) continue;
            if(i > 0 && arr[i-1] == arr[i] && !vis[i-1]) continue;
            vis[i] = 1;
            t += arr[i] + '0';
            dfs(arr, t, n+1);
            t.pop_back();
            vis[i] = 0;
        }
    }
    string largestTimeFromDigits(vector<int>& arr) {
        string s = "";
        sort(arr.begin(), arr.end());
        dfs(arr, s, 0);
        if(res == "") return res;
        s = res.substr(0, 2) + ":" + res.substr(2, 2);
        return s;
    }
};