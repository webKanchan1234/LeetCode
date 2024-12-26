class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int row=grid.size();
        int col=grid[0].size();
        
        if(r<0 || r>=row || c<0 || c>=col || grid[r][c]!='1'){
            return;
        }
        vector<int> rNbr = {-1,0,1,0};
        vector<int> cNbr = {0,1,0,-1};
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            int nrow=r+rNbr[i];
            int ncol=c+cNbr[i];
            dfs(grid,nrow,ncol);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};