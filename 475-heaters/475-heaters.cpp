class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), m = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = max(houses[n-1], heaters[m-1]);
        while(l < r){
            int mid = l + r >> 1;
            if(check(houses, heaters, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    bool check(vector<int>& houses,vector<int>& heaters ,int x){
        int n = houses.size(), m = heaters.size();
        for(int i = 0, j = 0; i < n; i++){
            while(j < m && abs(houses[i] - heaters[j]) > x)
                j++;
            if(j == m) return 0;
        }
        return 1;
    }
};