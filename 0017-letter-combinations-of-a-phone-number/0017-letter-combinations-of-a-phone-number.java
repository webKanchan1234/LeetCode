class Solution {
    private static final String[] MAP = {
        "",    "",    "abc",  "def",  "ghi",
        "jkl", "mno", "pqrs", "tuv",  "wxyz"
    };

    public void backtracking(String digits,int i,StringBuilder str,List<String> ans){
        if(digits.length()==i){
            ans.add(str.toString());
            return;
        }
        String w=MAP[digits.charAt(i)-'0'];
        for(char c:w.toCharArray()){
            str.append(c);
            backtracking(digits,i+1,str,ans);
            str.deleteCharAt(str.length()-1);
        }
    }

    public List<String> letterCombinations(String digits) {
        List<String> ans=new ArrayList<>();
        if(digits==null || digits.length()==0) return ans;
        backtracking(digits,0,new StringBuilder(),ans);
        return ans;
    }
}