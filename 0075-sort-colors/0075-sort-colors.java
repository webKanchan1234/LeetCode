class Solution {
    public void sortColors(int[] nums) {
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                cnt0++;
            }else if(nums[i]==1){
                cnt1++;
            }else{
                cnt2++;
            }
        }
        int i=0;
        while(cnt0>0){
            nums[i]=0;
            i++;
            cnt0--;
        }
        while(cnt1>0){
            nums[i]=1;
            i++;
            cnt1--;
        }
        while(cnt2>0){
            nums[i]=2;
            i++;
            cnt2--;
        }
    }
}