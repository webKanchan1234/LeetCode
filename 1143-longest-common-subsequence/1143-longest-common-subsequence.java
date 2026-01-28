class Solution {
    public int helper(String s1,String s2, int i, int j,int[][] dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1.charAt(i)==s2.charAt(j)){
            return dp[i][j]=1+helper(s1,s2,i-1,j-1,dp);
        }else{
            return dp[i][j]=Math.max(helper(s1,s2,i-1,j,dp),helper(s1,s2,i,j-1,dp));
        }


    }
    public int longestCommonSubsequence(String text1, String text2) {
        int i=text1.length();
        int j=text2.length();
        int[][] dp=new int[i][j];

        for(int[] r:dp){
            Arrays.fill(r,-1);
        }

        return helper(text1,text2,i-1,j-1,dp);
    }
}