class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n=cardPoints.length;
        int lsum=0;
        int rsum=0;
        int ridx=n-1;
        int ans=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        ans=lsum;

        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[ridx];
            ans=Math.max(lsum+rsum,ans);
            ridx--;
        }
        return ans;
    }
}