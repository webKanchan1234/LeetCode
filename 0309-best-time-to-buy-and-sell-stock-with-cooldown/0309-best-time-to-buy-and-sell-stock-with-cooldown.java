class Solution {
            public int helper(int[] prices,int i,int buy,Integer[][] dp){
        if(i>=prices.length){
            return 0;
        }

        if(dp[i][buy]!=null){
            return dp[i][buy];
        }

        if(buy==1){
            return dp[i][buy]=Math.max(-prices[i]+helper(prices,i+1,0,dp),
            helper(prices,i+1,1,dp));
        }else{
            return dp[i][buy]=Math.max(prices[i]+helper(prices,i+2,1,dp),
            helper(prices,i+1,0,dp));
        }

    }

    public int maxProfit(int[] prices) {
        int n=prices.length;
        Integer[][] dp=new Integer[n][2];

        return helper(prices,0,1,dp);
    }
}