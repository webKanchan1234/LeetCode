class Solution {
public:
    int helper(int n, int m,vector<vector<int>>grid,vector<vector<int>>& dp){
        if(n>=0 && m>=0 && grid[n][m]==1){
            return 0;
        }
        if(m==0 && n==0){
            return 1;
        }
        if(m<0 || n<0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        return dp[n][m]=helper(n-1,m,grid,dp)+helper(n,m-1,grid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,obstacleGrid,dp);

    }
};