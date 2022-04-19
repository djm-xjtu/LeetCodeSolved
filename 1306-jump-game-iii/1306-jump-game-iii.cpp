class Solution {
public:
    int h[100000];
    bool dfs(vector<int>& arr, int idx){
        if(arr[idx] == 0) return 1;
        if(!h[idx]){
            h[idx] = 1;
            if(idx + arr[idx] < arr.size() && dfs(arr, idx + arr[idx])) return 1;
            if(idx - arr[idx] >= 0 && dfs(arr, idx - arr[idx])) return 1;
            h[idx] = 0;
        }
        return 0;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = 0;
        for(auto i : arr){
            if(i == 0) n++;
        }
        return dfs(arr, start);
    }
};