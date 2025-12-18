class Solution {

    public int[][] updateMatrix(int[][] mat) {
        Queue<int[]>q=new LinkedList<>();
        int n=mat.length;
        int m=mat[0].length;
        int[][] ans=new int[n][m];
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j] = 0;
                    q.offer(new int[]{i,j});
                }else {
                    ans[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        int[] ax={-1,1,0,0};
        int[] ay={0,0,1,-1};

        while(!q.isEmpty()){
            int[] cell=q.poll();
            int sz=q.size();
            int r=cell[0];
            int c=cell[1];

            for(int i=0;i<4;i++){
                int x=r+ax[i];
                int y=c+ay[i];
                if(x>=0 && x<n && y>=0 && y<m && ans[x][y]>ans[r][c]+1){
                    ans[x][y]=ans[r][c]+1;
                    q.offer(new int[]{x,y});
                }
            }

        }
        return ans;
    }
}