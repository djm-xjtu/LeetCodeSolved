class Solution {
public:
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for(int i = 0; i < n; i++){
            int a = 0, b = 0, res = 0;
            unordered_map<string, int> h;
            for(int j = i; j < n; j++){
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) a++;
                else if(points[i][0] == points[j][0]) b++;
                else{
                    int x = points[j][0] - points[i][0], y = points[j][1] - points[i][1];
                    int k = gcd(x, y);
                    x /= k, y /= k;
                    string t = to_string(x) + "/" + to_string(y);
                    h[t]++;
                }
            }
            res += a;
            res += b;
            for(auto [a, b] : h) res = max(res, b + 1);
            ans = max(ans, res);
        }
        return ans;
    }
};