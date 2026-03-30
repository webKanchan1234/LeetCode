class Solution {
    public int maxProduct(int[] nums) {
        int n=nums.length;
        int mxprod=nums[0];
        int mnprod=nums[0];
        int ans=nums[0];

        for(int i=1;i<n;i++){
            if(nums[i]<0){
                int t=mxprod;
                mxprod=mnprod;
                mnprod=t;
            }

            mxprod=Math.max(nums[i],nums[i]*mxprod);
            mnprod=Math.min(nums[i],nums[i]*mnprod);

            ans=Math.max(ans,mxprod);
        }
        return ans;
    }
}