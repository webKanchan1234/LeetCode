class Solution {
    public long helper(int[] piles,int k){
        long total=0;
        for(int p:piles){
            total+=(p+k-1)/k;
        }
        return total;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int n=piles.length;
        int l=1;
        int r=0;
        int ans=r;

        for(int num:piles){
            r=Math.max(r,num);
        }

        while(l<=r){
            int m=l+(r-l)/2;

            long time=helper(piles,m);

            if(time<=h){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
}