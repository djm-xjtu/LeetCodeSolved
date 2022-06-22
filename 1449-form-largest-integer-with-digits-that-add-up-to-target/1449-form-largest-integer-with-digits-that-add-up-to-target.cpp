class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        string f[target + 1];
        for(int i = 0; i <= target; i++){
            f[i] = "0";
        }
        f[0] = "";
        for(int i = 1; i <= n; i++){
            for(int j = cost[i-1]; j <= target; j++){
                if(f[j - cost[i-1]] != "0"){
                    string t = to_string(i) + f[j - cost[i-1]];
                    f[j] = check(f[j], t);
                }
            }
        }
        return f[target];
    }
    string check(string a, string b){
        if(a.size() > b.size()) return a;
        else if(a.size() < b.size()) return b;
        else return max(a, b);
    }
};