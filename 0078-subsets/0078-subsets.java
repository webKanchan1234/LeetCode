class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        int n=nums.length;
        List<List<Integer>> ans=new ArrayList<>();
        int subset=1<<n;

        for(int mask=0;mask<subset;mask++){
            List<Integer> temp=new ArrayList<>();
            for(int i=0;i<n;i++){
                if((mask & (1<<i))!=0){
                    temp.add(nums[i]);
                }
            }
            ans.add(temp);
        }
        return ans;
    }
}