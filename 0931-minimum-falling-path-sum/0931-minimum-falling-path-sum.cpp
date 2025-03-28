class Solution {
public:
    int helper(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if (j < 0 || j >= m)
        return 1e9;
        if (i == 0)
        return matrix[0][j];
        if (dp[i][j] != -1)
        return dp[i][j];

        int upr=matrix[i][j]+helper(i - 1, j + 1, m, matrix, dp);
        int up=matrix[i][j]+helper(i - 1, j, m, matrix, dp);
        int upl=matrix[i][j]+helper(i - 1, j - 1, m, matrix, dp);
        return dp[i][j]=min(upr,min(up,upl));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int mn=INT_MAX;
        for(int i=0;i<m;i++){
            int v=helper(n - 1, i, m, matrix, dp);
            mn=min(mn,v);
        }
        return mn;
    }
};