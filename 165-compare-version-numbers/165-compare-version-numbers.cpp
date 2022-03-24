class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(i < n && version1[i] == '.') i++;
            if(j < m && version2[j] == '.') j++;
            int k1 = i, k2 = j;
            while(i < n && version1[i] != '.') i++;
            while(j < m && version2[j] != '.') j++;
            string s1 = version1.substr(k1, i - k1);
            string s2 = version2.substr(k2, j - k2);
            int t1 = stoi(s1);
            int t2 = stoi(s2);
            if(t1 < t2) return -1;
            else if(t1 > t2) return 1;
        }
        while(i < n){
            if(i < n && version1[i] == '.') i++;
            int k1 = i;
            while(i < n && version1[i] != '.') i++;
            string s1 = version1.substr(k1, i - k1);
            int t1 = stoi(s1);
            if(t1 > 0) return 1;
        }
        while(j < m){
            if(j < m && version2[j] == '.') j++;
            int k2 = j;
            while(j < m && version2[j] != '.') j++;
            string s2 = version2.substr(k2, j - k2);
            int t2 = stoi(s2);
            if(t2 > 0) return -1;
        }
        return 0;
    }
};