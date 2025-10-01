class Solution {
    public int trap(int[] height) {
        
        int l=0;
        int r=height.length-1;

        int lm=0;
        int rm=0;
        int sum=0;

        while(l<r){
            if(height[l]<height[r]){
                if(height[l]>=lm){
                    lm=height[l];
                }else{
                    sum+=lm-height[l];
                }
                l++;
            }else{
                if(height[r]>=rm){
                    rm=height[r];
                }else{
                    sum+=rm-height[r];
                }
                r--;
            }
        }
        return sum;

    }
}