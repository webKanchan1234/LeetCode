class Solution {
    public boolean helper(int i,int[] nums,int tar,Boolean[][] dp){
        if(tar==0){
            return true;
        }
        if(i==nums.length-1){
            return nums[i]==tar;
        }

        if(dp[i][tar]!=null){
            return dp[i][tar];
        }

        boolean not=helper(i+1,nums,tar,dp);
        boolean pick=false;

        if(nums[i]<=tar){
            pick=helper(i+1,nums,tar-nums[i],dp);
        }

        return dp[i][tar]=not|| pick;

    }
    public boolean canPartition(int[] nums) {
        int n=nums.length;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2!=0){
            return false;
        }

        Boolean[][] dp=new Boolean[n][sum/2+1];


        return helper(0,nums,sum/2,dp);
    }
}