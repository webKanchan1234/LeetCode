class Solution {

    public boolean dfs(int st,String s,Set<String> dict,Boolean[] memo){
        if(st==s.length()) return true;

        if(memo[st]!=null) return memo[st];

        for(int i=st+1;i<=s.length();i++){
            if(dict.contains(s.substring(st,i)) && dfs(i,s,dict,memo)){
                return memo[st] = true;
            }
        }
        return memo[st] = false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> dict=new HashSet<>(wordDict);
        Boolean[] memo=new Boolean[s.length()];

        return dfs(0,s,dict,memo);
        
    }
}