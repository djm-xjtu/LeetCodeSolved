class Solution {
public:
    int findComplement(int num) {
        if (!num) return 1;

        int tot = 0;
        for (int x = num; x; x -= x & -x)
            tot = x;

        return ~num & (tot - 1);
    }
};