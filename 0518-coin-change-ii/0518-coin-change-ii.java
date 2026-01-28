class Solution {
    public int helper(int[] coins,int amount,int i,Integer[][] dp){
        if(amount==0){
            return 1;
        }
        if(amount<0 || i>=coins.length){
            return 0;
        }

        if(dp[i][amount]!=null){
            return dp[i][amount];
        }

        int take=0;
        take=helper(coins,amount-coins[i],i,dp);
        int not=helper(coins,amount,i+1,dp);

        return dp[i][amount]=take+not;
    }
    public int change(int amount, int[] coins) {
        int n=coins.length;
        Integer[][] dp=new Integer[n][amount+1];
        return helper(coins,amount,0,dp);
    }
}