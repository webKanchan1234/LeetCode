class Solution {

    public boolean isPalindrom(int i,int j,String s){

        while(i<j){
            if(s.charAt(i++)!=s.charAt(j--)){
                return false;
            }
        }
        return true;
    }

    public void backtracking(int st, String s,List<String> temp,List<List<String>> ans){
        if(st==s.length()){
            ans.add(new ArrayList<>(temp));
            return;
        }

        for(int end=st;end<s.length();end++){
            if(isPalindrom(st,end,s)){
                temp.add(s.substring(st,end+1));
                backtracking(end+1,s,temp,ans);
                temp.remove(temp.size()-1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> ans=new ArrayList<>();
        backtracking(0,s,new ArrayList<>(),ans);
        return ans;
    }
}