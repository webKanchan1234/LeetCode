class Solution {
    public int findMin(int[] nums) {
        int n=nums.length;
        int ans=Integer.MAX_VALUE;
        int l=0;
        int h=n-1;

        while(l<=h){

            if(nums[l]<=nums[h]){
                ans=Math.min(nums[l],ans);
                break;
            }

            int m=l+(h-l)/2;

            if(nums[l]<=nums[m]){
                ans=Math.min(nums[l],ans);
                l=m+1;
            }else{
                ans=Math.min(nums[m],ans);
                h=m-1;
            }
        }

        return ans;
    }
}