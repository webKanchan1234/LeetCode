class Solution {
    public void dfs(int r,int c,int[][] grid){
        int n=grid.length;
        int m=grid[0].length;

        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]==0){
            return;
        }

        grid[r][c]=0;
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r+1,c,grid);
        dfs(r,c-1,grid);
    }
    public int numEnclaves(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;

        for(int i=0;i<n;i++){
            dfs(i,0,grid);
            dfs(i,m-1,grid);
        }

        for(int i=0;i<m;i++){
            dfs(0,i,grid);
            dfs(n-1,i,grid);
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
}