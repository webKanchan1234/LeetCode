class Solution {
public:
    void bfs(vector<vector<int>>& image, int r, int c,int prevColor, int color){

        int n=image.size();
        int m=image[0].size();
        if(image[r][c]==prevColor){
            image[r][c]=color;
        }
        queue<pair<int,int>>q;
        q.push({r,c});
        while(!q.empty()){
            int nr=q.front().first;
            int nc=q.front().second;
            q.pop();

            if(nr-1>=0 && image[nr-1][nc]==prevColor){
                image[nr-1][nc]=color;
                q.push({nr-1,nc});
            }
            if(nc+1<m && image[nr][nc+1]==prevColor){
                image[nr][nc+1]=color;
                q.push({nr,nc+1});
            }
            if(nr+1<n && image[nr+1][nc]==prevColor){
                image[nr+1][nc]=color;
                q.push({nr+1,nc});
            }
            if(nc-1>=0 && image[nr][nc-1]==prevColor){
                image[nr][nc-1]=color;
                q.push({nr,nc-1});
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevColor=image[sr][sc];
        if(prevColor==color){
            return image;
        }
        bfs(image,sr,sc,prevColor,color);
        return image;
    }
};