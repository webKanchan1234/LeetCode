class Solution {

    public void helper(int[] cand,int tar,int start, List<List<Integer>> ans,List<Integer> temp){

        if(tar==0){
            ans.add(new ArrayList(temp));
            return;
        }

        if (tar < 0) return;

        for (int i = start; i < cand.length; i++) {
            if (i > start && cand[i] == cand[i - 1]) continue; 

            temp.add(cand[i]);
            helper(cand, tar - cand[i], i + 1, ans, temp);
            temp.remove(temp.size() - 1); 
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
        Arrays.sort(candidates);
        helper(candidates,target,0,ans,temp);
        return ans;
    }
}