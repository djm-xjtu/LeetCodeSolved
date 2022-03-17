class Solution {
public:
    void quick_sort(vector<int>& a, int l, int r){
        if(l >= r) return;
        int i = l-1, j = r+1, x = a[l+r>>1];
        while(i < j){
            do i++; while(a[i] < x);
            do j--; while(a[j] > x);
            if(i < j) swap(a[i], a[j]);
        }
        quick_sort(a, l, j);
        quick_sort(a, j+1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size()-1);
        return nums;
    }
};