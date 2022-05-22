class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0;
        vector<int> div;
        for(int i = 1; i * i <= k; i++){
            if(k % i == 0) {
                div.push_back(i);
                if(i * i != k) div.push_back(k / i);
            }
        }
        unordered_map<int, int> h;
        for(auto st : nums){
            ans += h[k / gcd(k, st)];
            for(auto t : div){
                if(st % t == 0) h[t]++;
            }
        }
        return ans;
    }
};