class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        int min_val = 0;
        for(auto i : sums) min_val = min(min_val, i);
        min_val = -min_val;
        multiset<int> st;
        for(auto i : sums) st.insert(i + min_val);
        st.erase(st.begin());
        vector<int> ans;
        ans.push_back(*st.begin());
        for(int i = 1; i < n; i++){
            for(int j = 0; j < (1 << i); j++){
                if(j >> (i - 1) & 1){
                    int sm = 0;
                    for(int k = 0; k < i; k++){
                        if(j >> k & 1) sm += ans[k];
                    }
                    st.erase(st.find(sm));
                }
            }
            ans.push_back(*st.begin());
        }
        for(int i = 0; i < 1 << n; i++){
            int sm = 0;
            for(int j = 0; j < n; j++){
                if(i >> j & 1) sm += ans[j];
            }
            if(sm == min_val){
                for(int j = 0; j < n; j++){
                    if(i >> j & 1) ans[j] = -ans[j];
                }
                break;
            }
        }
        return ans;
    }
};