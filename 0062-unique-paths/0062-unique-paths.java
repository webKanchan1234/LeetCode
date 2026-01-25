class Solution {
    public int helper(int i,int j, int n, int m,int[][] dp){
        if(i==n || j==m){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        return dp[i][j]=helper(i+1,j,n,m,dp)+helper(i,j+1,n,m,dp);
    }
    public int uniquePaths(int m, int n) {
        int[][] dp=new int[n][m];
        for (int i = 0; i < n; i++) {
    Arrays.fill(dp[i], -1);
}
        return helper(0,0,n,m,dp);
    }
}