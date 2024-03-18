class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorn=start^goal;
        int cnt=0;
        while(xorn!=0){
            int rmb=(xorn & -xorn);
            xorn-=rmb;
            cnt++;
        }
        return cnt;
    }
};