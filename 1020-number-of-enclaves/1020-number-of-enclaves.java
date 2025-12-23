class Solution {
    public int count(int[][] grid) {
        int cnt = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    public int numEnclaves(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        Queue<int[]> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                q.offer(new int[] { i, 0 });
            }

            if (grid[i][m - 1] == 1) {
                q.offer(new int[] { i, m - 1 });
            }
        }

        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1) {
                q.offer(new int[] { 0, i });
            }

            if (grid[n - 1][i] == 1) {
                q.offer(new int[] { n - 1, i });
            }
        }

        int[] ax={-1,1,0,0};
        int[] ay={0,0,1,-1};

        while(!q.isEmpty()){
            int[] cell=q.poll();
            int r=cell[0];
            int c=cell[1];
            if(r<0 || c<0 || r>=n || c>=m || grid[r][c]==0) continue;
            grid[r][c]=0;

            for(int i=0;i<4;i++){
                int x=ax[i]+r;
                int y=ay[i]+c;
                q.offer(new int[]{x,y});
            }

        }
        return count(grid);
    }
}