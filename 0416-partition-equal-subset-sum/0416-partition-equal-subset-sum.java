class Solution {
    public boolean helper(int i,int tar,int[] nums){
        if(tar==0){
            return true;
        }

        if(i==0){
            return nums[0]==tar;
        }

        boolean notpic=helper(i-1,tar,nums);
        boolean pick=false;
        if(nums[i]<=tar){
            pick=helper(i-1,tar-nums[i],nums);
        }

        return pick || notpic;
    }
    public boolean canPartition(int[] nums) {
        int sum=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }

        return helper(n-1,sum/2,nums);
    }
}