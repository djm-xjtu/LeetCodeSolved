class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        sort(changed.begin(), changed.end());
        int n = changed.size();
        if(n & 1 || n == 0) return {};
        multiset<int> st;
        multiset<int> t;
        for(int i = 0; i < n; i++) st.insert(changed[i]);
        while(st.size()){
            ans.push_back(*st.begin());
            st.erase(st.begin());
            if(st.find(ans.back() * 2) == st.end()) return {};
            st.erase(st.find(ans.back() * 2));
        }
        return ans;
    }
};