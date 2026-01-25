class Solution {
    public int helper(int i,int j,int n,int m, int[][] obstacleGrid,int[][] dp){
        if(i>=n || j>=m){
            return 0;
        }

if (obstacleGrid[i][j] == 1) return 0;
        if(i==n-1 && j==m-1){
            return 1;
        }

        

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        return dp[i][j]=helper(i+1,j,n,m,obstacleGrid,dp)+helper(i,j+1,n,m,obstacleGrid,dp);
    }

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n=obstacleGrid.length;
        int m=obstacleGrid[0].length;

        int[][] dp=new int[n][m];
        if (obstacleGrid[0][0] == 1) return 0;
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return helper(0,0,n,m,obstacleGrid,dp);
    }

}