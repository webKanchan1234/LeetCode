class Solution {
public:
   
    int hammingDistance(int x, int y) {
        int ans=0;
        int xr=x^y;
        while(xr){
            ans++;
            xr = xr&(xr-1);
        }
        return ans;
    }
};