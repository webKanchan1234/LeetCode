class Solution {
    public int helper(String w1, String w2,int i, int j,int[][] dp){
        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(w1.charAt(i)==w2.charAt(j)){
            return dp[i][j]=1+helper(w1,w2,i-1,j-1,dp);
        }else{
            return dp[i][j]=Math.max(helper(w1,w2,i-1,j,dp),helper(w1,w2,i,j-1,dp));
        }
    }
    public int minDistance(String word1, String word2) {
        int n=word1.length();
        int m=word2.length();
        int[][] dp=new int[n][m];

        for(int[] r:dp){
            Arrays.fill(r,-1);
        }

        return n+m-2*helper(word1,word2,n-1,m-1,dp);
    }
}