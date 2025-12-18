class Solution {
    public boolean isValid(int[][] image,int i, int j, int n, int m, int color){
        if(i>=0 && i<n && j>=0 && j<m && image[i][j]==color){
            return true;
        }
        return false;
    }
   
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int n=image.length;
        int m=image[0].length;
        Queue<int[]>q=new LinkedList<>();
        q.offer(new int[]{sr,sc});
        int curr=image[sr][sc];
        image[sr][sc]=color;
        
        if(curr==color){
            return image;
        }

        int[] ax={-1,1,0,0};
        int[] ay={0,0,1,-1};

        while(!q.isEmpty()){
            int[] cell=q.poll();

            for(int i=0;i<4;i++){
                int x=ax[i]+cell[0];
                int y=ay[i]+cell[1];

                if(isValid(image,x,y,n,m,curr)){
                    image[x][y]=color;
                    q.offer(new int[]{x,y});
                }
            }
            
        }
        return image;
    }
}