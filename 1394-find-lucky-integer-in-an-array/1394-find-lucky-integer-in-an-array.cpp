class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> h;
        for(auto i : arr){
            h[i]++;
        }
        int res = -1;
        for(auto&[a,b] : h){
            if(a == b) res = max(res, a);
        }
        return res;
    }
};