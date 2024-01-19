class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int j=0;j<m;j++)
            dp[0][j]=matrix[0][j];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){       
                int a = matrix[i][j] + dp[i-1][j];
                int b = matrix[i][j]; 
                    if(j-1>=0)
                        b += dp[i-1][j-1];
                    else
                        b+= 1e9;
                int c = matrix[i][j]; 
                    if(j+1<m)
                        c+= dp[i-1][j+1];
                    else
                        c+= 1e9;
                
                dp[i][j] = min(a,min(b,c));
            }
        }

        int res = 1e9;
        
        for(int k=0;k<m;k++)
            res = min(res,dp[n-1][k]);
        
        return res;

    }
};