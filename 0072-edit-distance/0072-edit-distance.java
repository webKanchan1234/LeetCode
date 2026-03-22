class Solution {
    public int helper(String word1, String word2,int i,int j, Integer[][] dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }

        if(dp[i][j]!=null){
            return dp[i][j];
        }
        if(word1.charAt(i) == word2.charAt(j)){
            return dp[i][j] = helper(word1,word2,i-1, j-1, dp);
        }

        int insert=1+helper(word1,word2,i,j-1,dp);
        int delete=1+helper(word1,word2,i-1,j,dp);
        int replace=1+helper(word1,word2,i-1,j-1,dp);

        return dp[i][j]=Math.min(insert,Math.min(delete,replace));

    }
    public int minDistance(String word1, String word2) {
        int n=word1.length();
        int m=word2.length();

        Integer[][] dp=new Integer[n][m];

        return helper(word1,word2,n-1,m-1,dp);
    }
}