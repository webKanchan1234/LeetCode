class Solution {
    public double myPow(double x, int n) {
        long pw=n;
        if(pw<0){
            x=1/x;
            pw=-pw;
        }

        double ans=1.0;

        while(pw>0){
            if((pw&1)==1){
                ans*=x;
            }
            x*=x;
            pw>>=1;
        }
        return ans;
    }
}