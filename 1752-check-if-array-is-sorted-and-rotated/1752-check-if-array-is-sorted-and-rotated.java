class Solution {
    public boolean check(int[] nums) {
        int x=0;
        int len=nums.length;
        int[] temp=new int[len];
        for(int i=0;i<len-1;i++){
            if(nums[i]>nums[i+1]){
                x=i+1;
            }
        }
        System.out.println(x);
        for(int i=0;i<len;i++){
            temp[i]=nums[(i+x)%len];
        }
        for(int i=0;i<len-1;i++){
            System.out.println(temp[i]);
            if(temp[i]>temp[i+1]){
                return false;
            }
        }

        return true;
    }
}