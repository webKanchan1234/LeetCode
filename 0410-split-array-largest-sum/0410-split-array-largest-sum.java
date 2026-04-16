class Solution {
    public boolean canSplit(int[] nums,int k, int mxsum){
        int sum=0;
        int cnt=1;

        for(int num:nums){
            if(num+sum>mxsum){
                cnt++;
                sum=num;
            }else{
                sum+=num;
            }
        }

        return cnt<=k;
    }
    public int splitArray(int[] nums, int k) {
        int n=nums.length;
        int l=0;
        int h=0;
        int ans=h;

        for(int num:nums){
            l=Math.max(num,l);
            h+=num;
        }

        while(l<=h){
            int m=(h+l)/2;

            if(canSplit(nums,k,m)){
                ans=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }

        return ans;
    }
}