class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorn=start^goal;
        int ans=__builtin_popcount(xorn);
        return ans;
    }
};