class Solution {
    public int helper(int[] nums,int tar,int i){

        if (i == nums.length) {
            return tar == 0 ? 1 : 0;
        }

        int take=helper(nums,tar-nums[i],i+1);
        int not=helper(nums,tar-(-nums[i]),i+1);

        return take+not;

    }
    public int findTargetSumWays(int[] nums, int target) {
        int n=nums.length;

        return helper(nums,target,0);
    }
}