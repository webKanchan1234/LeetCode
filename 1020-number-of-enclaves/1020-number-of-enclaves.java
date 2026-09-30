class Solution {

    public void dfs(int[][] grid,int r,int c){
        if(r<0 | c<0 || r>=grid.length || c>=grid[0].length){
            return;
        }

        if(grid[r][c]==0){
            return;
        }

        grid[r][c]=0;

        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r+1,c);
        dfs(grid,r,c-1);
    }
    public int numEnclaves(int[][] grid) {
        int r=grid.length;
        int c=grid[0].length;

        int cnt=0;

        for(int i=0;i<c;i++){
            if(grid[0][i]==1){
                dfs(grid,0,i);
            }

            if(grid[r-1][i]==1){
                dfs(grid,r-1,i);
            }
        }

        for(int i=0;i<r;i++){
            if(grid[i][0]==1){
                dfs(grid,i,0);
            }

            if(grid[i][c-1]==1){
                dfs(grid,i,c-1);
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
}