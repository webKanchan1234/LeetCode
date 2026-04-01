class Solution {
    public void dfs(int r,int c,char[][] grid,boolean[][] vis){
        int n=grid.length;
        int m=grid[0].length;
        

        if(r<0 || c<0 || r>=n || c>=m || vis[r][c] ||grid[r][c] == '0'){
            return;
        }
        vis[r][c]=true;

        dfs(r-1,c,grid,vis);
        dfs(r,c+1,grid,vis);
        dfs(r+1,c,grid,vis);
        dfs(r,c-1,grid,vis);

    }
    public int numIslands(char[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        int ans=0;

        boolean[][] vis=new boolean[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }

        return ans;

    }
}