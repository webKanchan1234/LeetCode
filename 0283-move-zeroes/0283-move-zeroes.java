class Solution {
    public void moveZeroes(int[] nums) {
        Integer cnt0=0;
        int j=0;
        int[] temp=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                cnt0++;
            }else{
                temp[j]=nums[i];
                j++;
            }
        }
        for(int i=0;i<temp.length;i++){
            nums[i]=temp[i];
        }
    }
}