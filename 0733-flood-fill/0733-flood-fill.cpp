class Solution {
public:
    void helper(vector<vector<int>>& image, int r, int c,int prevColor, int color){

        int n=image.size();
        int m=image[0].size();
        if(image[r][c]!=prevColor){
            return;
        }

        image[r][c]=color;

        if(r-1>=0){
            helper(image,r-1,c,prevColor,color);
        }
        if(c+1<m){
            helper(image,r,c+1,prevColor,color);
        }
        if(r+1<n){
            helper(image,r+1,c,prevColor,color);
        }
        if(c-1>=0){
            helper(image,r,c-1,prevColor,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevColor=image[sr][sc];
        if(prevColor==color){
            return image;
        }
        helper(image,sr,sc,prevColor,color);
        return image;
    }
};