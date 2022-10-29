class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if(sum1 > sum2) swap(nums1, nums2), swap(sum1, sum2);
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = m - 1;
        int ans = 0;
        while(sum1 < sum2 && i < n && j >= 0){
            if(6-nums1[i] > nums2[j]-1){
                sum1 += 6-nums1[i];
                i++;
            }
            else{
                sum2 -= nums2[j]-1;
                j--;
            }
            ans++;
        }
        while(sum1 < sum2 && i < n){
            sum1 += 6-nums1[i];
            i++;
            ans++;
        }
        while(sum1 < sum2 && j >= 0){
            sum2 -= nums2[j]-1;
            j--;
            ans++;
        }
        return sum1 < sum2 ? -1 : ans;
    }
};