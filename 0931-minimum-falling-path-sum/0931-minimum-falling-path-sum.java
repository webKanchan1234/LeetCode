class Solution {
    
    public int helper(int i,int j, int n, int m, int[][] matrix,int[][] dp){
        if(j<0 || j>=n){
            return Integer.MAX_VALUE;
        }
        if(i==n-1){
            return matrix[i][j];
        }

        if(dp[i][j]!=Integer.MAX_VALUE){
            return dp[i][j];
        }

        int dl=helper(i+1,j-1,n,m,matrix,dp);
        int db=helper(i+1,j,n,m,matrix,dp);
        int dr=helper(i+1,j+1,n,m,matrix,dp);

        return dp[i][j]=matrix[i][j]+Math.min(db,Math.min(dl,dr));
    }
    public int minFallingPathSum(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        int ans=Integer.MAX_VALUE;
        int[][] dp=new int[n][n];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],Integer.MAX_VALUE);
        }

        for(int j=0;j<n;j++){
            ans=Math.min(ans,helper(0,j,n,m,matrix,dp));
        }

        return ans;
    }
}