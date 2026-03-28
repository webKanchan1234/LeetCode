class Solution {

        public int helper(int[] prices,int i,int buy,int cap,Integer[][][] dp){
        if(i==prices.length|| cap==0){
            return 0;
        }

        if(dp[i][buy][cap]!=null){
            return dp[i][buy][cap];
        }

        if(buy==1){
            return dp[i][buy][cap]=Math.max(-prices[i]+helper(prices,i+1,0,cap,dp),
            helper(prices,i+1,1,cap,dp));
        }else{
            return dp[i][buy][cap]=Math.max(prices[i]+helper(prices,i+1,1,cap-1,dp),
            helper(prices,i+1,0,cap,dp));
        }

    }

    public int maxProfit(int k, int[] prices) {
        int n=prices.length;
        Integer[][][] dp=new Integer[n][2][k+1];

        return helper(prices,0,1,k,dp);
    }
}