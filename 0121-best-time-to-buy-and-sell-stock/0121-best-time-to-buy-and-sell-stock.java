class Solution {
    public int maxProfit(int[] prices) {
        int mn=Integer.MAX_VALUE;
        int ans=0;

        for(int val:prices){
            if(val<mn){
                mn=val;
            }else{
                ans=Math.max(ans,val-mn);
            }
        }
        return ans;
    }
}