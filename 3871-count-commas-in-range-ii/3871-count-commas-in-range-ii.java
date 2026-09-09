class Solution {
    public long countCommas(long n) {
        long x=1000;
        long ans=0;
        while(x<=n){
            ans+=n-x+1;
            x*=1000;
        }

        return ans;
    }
}