class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    vector<vector<int>> ans;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 按head节点排序
        sort(intervals.begin(), intervals.end(), cmp);
        if(intervals.size() == 1) return intervals;
        ans.push_back(intervals[0]);
        int Max = intervals[0][1];
        for(int i = 0; i < intervals.size()-1; i++){
            if(Max < intervals[i+1][0]) ans.push_back(intervals[i+1]);
            if(Max >= intervals[i+1][1]) continue;
            if(Max < intervals[i+1][1] && Max >= intervals[i+1][0]) add(intervals[i+1]);
            Max = max(Max, intervals[i+1][1]);
        }
        return ans;
    }
    void add(vector<int> a){
        vector<int> x = ans.back();
        if(a[0] > x[1]) ans.push_back(a);
        if(x[0] <= a[0] && x[1] >= a[1]) return;
        if(x[0] <= a[0] && x[1] < a[1]){
            ans.pop_back();
            ans.push_back({x[0], a[1]});
        }
    }
};