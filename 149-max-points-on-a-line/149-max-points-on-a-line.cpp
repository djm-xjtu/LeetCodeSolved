class Solution {
public:
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<string, int> h;
            int a = 0, b = 0;
            for(int j = i; j < points.size(); j++){
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) a++;
                else if(points[i][0] == points[j][0]) b++;
                else{
                    int x = points[j][0] - points[i][0];
                    int y = points[j][1] - points[i][1];
                    int c = gcd(x, y); //求出公约数，化简形式
                    x /= c;
                    y /= c;
                    string t = to_string(x) + "/" + to_string(y);
                    h[t]++;
                }
            }
            int res = b;
            for(auto i = h.begin(); i != h.end(); i++) res = max(res, i->second);
            ans = max(ans, res + a);
        }
        return ans;
    }
};