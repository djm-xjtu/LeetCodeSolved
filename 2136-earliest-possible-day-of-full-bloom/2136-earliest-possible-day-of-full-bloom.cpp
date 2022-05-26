class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = growTime.size();
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 0);
        sort(arr.begin(), arr.end(), [&growTime](int x, int y){
            return growTime[x] > growTime[y];
        });
        int plant = 0, time = 0;
        for(auto i : arr){
            plant += plantTime[i];
            time = max(time, plant + growTime[i]);
        }
        return time;
    }
};