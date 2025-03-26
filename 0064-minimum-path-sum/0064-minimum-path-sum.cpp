class Solution {
public:
    int helper(int n,int m,vector<vector<int>> &grid,vector<vector<int>>&dp){
        if(n==0 && m==0){
            return grid[n][m];
        }
        if(n<0 ||m<0){
            return INT_MAX;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        long up=helper(n-1,m,grid,dp);
        long left=helper(n,m-1,grid,dp);
        return dp[n][m]=grid[n][m]+min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,grid,dp);
    }
};