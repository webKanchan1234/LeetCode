class Solution {

    public int helper(int[] nums,int s,int n,int[] dp){
        if(n<s){
            return 0;
        }
        if(n==s){
            return nums[n];
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }

        int pick=nums[n] + helper(nums,s,n-2,dp);
        int notpic=helper(nums,s,n-1,dp);

        return dp[n]=Math.max(pick,notpic);
    }
    public int rob(int[] nums) {
        int n=nums.length;
        if(n==1){
            return nums[0];
        }
        int[] dp=new int[n];
        int[] dp1=new int[n];
        Arrays.fill(dp,-1);
        Arrays.fill(dp1,-1);
        int case1=helper(nums,0,n-2,dp);
        int case2=helper(nums,1,n-1,dp1);

        return Math.max(case1,case2);
    }
}