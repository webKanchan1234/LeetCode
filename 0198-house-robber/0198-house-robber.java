class Solution {
    public int helper(int[] nums,int n,int[] dp){
        if(n==0){
            return nums[n];
        }
        if(n<0){
            return 0;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        int pick=nums[n]+helper(nums,n-2,dp);
        int notpic=helper(nums,n-1,dp);
        return dp[n]=Math.max(pick,notpic);
    }
    public int rob(int[] nums) {
        int n=nums.length;
        int[] dp=new int[n];
        Arrays.fill(dp, -1);  
        return helper(nums,n-1,dp);
    }
}