class Solution {
    public boolean isValid(int[][] image,int i, int j, int n, int m, int color){
        if(i>=0 && i<n && j>=0 && j<m && image[i][j]==color){
            return true;
        }
        return false;
    }
    public void dfs(int[][] image, int i, int j, int n,int m,int currentcolor,int color){
        image[i][j]=color;
        if(isValid(image,i-1,j,n,m,currentcolor)){
            dfs(image,i-1,j,n,m,currentcolor,color);
        }

        if(isValid(image,i+1,j,n,m,currentcolor)){
            dfs(image,i+1,j,n,m,currentcolor,color);
        }

        if(isValid(image,i,j-1,n,m,currentcolor)){
            dfs(image,i,j-1,n,m,currentcolor,color);
        }

        if(isValid(image,i,j+1,n,m,currentcolor)){
            dfs(image,i,j+1,n,m,currentcolor,color);
        }
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int n=image.length;
        int m=image[0].length;
        int currentcolor=image[sr][sc];
        if(currentcolor==color){
            return image;
        }

        dfs(image,sr,sc,n,m,currentcolor,color);
        return image;
    }
}