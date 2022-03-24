class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;
        while(i < n || j < m){
            int k1 = i, k2 = j;
            while(k1 < n && version1[k1] != '.') k1++;
            while(k2 < m && version2[k2] != '.') k2++;
            string s1,s2;
            if(k1 != i) s1 = version1.substr(i, k1 - i);
            if(k2 != j) s2 = version2.substr(j, k2 - j);
            int t1 = atoi(s1.c_str());
            int t2 = atoi(s2.c_str());
            if(t1 < t2) return -1;
            else if(t1 > t2) return 1;
            if(k1 != i) i = k1 + 1;
            if(k2 != j) j = k2 + 1;
        }
        return 0;
    }
};