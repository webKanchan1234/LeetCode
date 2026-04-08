class Solution {
    public boolean isValid(int[] nums,int div,int thres){
        int sum=0;
        for(int num:nums){
            sum+=(num+div-1)/div;
        }

        return sum<=thres;
    }
    public int smallestDivisor(int[] nums, int threshold) {
        int n=nums.length;
        int l=1;
        int r=0;
        for(int num:nums){
            r=Math.max(r,num);
        }

        int ans=r;

        while(l<=r){
            int m=(r+l)/2;

            if(isValid(nums,m,threshold)){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
}