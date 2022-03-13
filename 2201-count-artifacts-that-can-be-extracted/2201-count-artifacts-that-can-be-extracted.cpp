class Solution {
    typedef pair<int, int> pii;

    bool check(vector<int> &vec, set<pii> &st) {
        for (int i = vec[0]; i <= vec[2]; i++) for (int j = vec[1]; j <= vec[3]; j++)
            if (!st.count(pii(i, j))) return false;
        return true;
    }

public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        set<pii> st;
        for (auto &vec : dig) st.insert(pii(vec[0], vec[1]));
        int ans = 0;
        for (auto &vec : artifacts) if (check(vec, st)) ans++;
        return ans;
    }
};