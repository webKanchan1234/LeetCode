class Solution {
    public int orangesRotting(int[][] grid) {
        int r=grid.length;
        int c=grid[0].length;
        Queue<int[]> q=new LinkedList<>();
        int fresh=0;
        int min=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.offer(new int[]{i,j});
                }

                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int[][] dirs = {
            {-1, 0}, 
            {1, 0},  
            {0, -1},
            {0, 1}   
        };

        while(!q.isEmpty()&& fresh > 0){
            int sz=q.size();

            for(int i=0;i<sz;i++){
                int[] curr=q.poll();
                int row=curr[0];
                int col=curr[1];


                for(int[] dir:dirs){
                    int nr=row+dir[0];
                    int nc=col+dir[1];

                    if(nr<0 || nc<0 || nr>=r || nc>=c){
                        continue;
                    }

                    if(grid[nr][nc]!=1){
                        continue;
                    }

                    fresh--;

                    grid[nr][nc]=2;
                    q.offer(new int[]{nr,nc});
                }



            }

            min++;
        }

        return fresh == 0 ? min : -1;
    }
}