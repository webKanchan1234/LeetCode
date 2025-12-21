class Solution {

    public void helper(int st,int k, int tar,List<List<Integer>> ans, List<Integer> list){
        if(k==0 && tar==0){
            ans.add(new ArrayList<>(list));
            return;
        }

        if(k==0 || tar<0){
            return;
        }

        for(int i=st;i<=9;i++){
            list.add(i);
            helper(i+1,k-1,tar-i,ans,list);
            list.remove(list.size()-1);
        }
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> list=new ArrayList<>();

        helper(1,k,n,ans,list);
        return ans;
    }
}