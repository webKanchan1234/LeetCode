class Solution {
    public int maxDepth(String s) {
        int n=s.length();
        int ans=0;
        int dep=0;

        for(int i=0;i<n;i++){
            if(s.charAt(i)=='('){
                dep++;
                ans=Math.max(ans,dep);
            }else if(s.charAt(i)==')'){
                dep--;
            }
        }
        return ans;
    }
}