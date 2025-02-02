class Solution {
    public boolean check(int[] nums) {
        int cnt=0;
        int len=nums.length;
        for(int i=0;i<len;i++){
            if(nums[i]>nums[(i+1)%len]){
                cnt++;
                if(cnt>1){
                    return false;
                }
            }
        }

        return true;
    }
}