class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int x, int y){
        int n=board.size();
        int m=board[0].size();
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nr=x+row[i];
            int nc=y+col[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O' && vis[nr][nc]==0){
                dfs(board,vis,nr,nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && vis[0][i]==0){
                dfs(board,vis,0,i);
            }
            if(board[n-1][i]=='O' && vis[n-1][i]==0){
                dfs(board,vis,n-1,i);
            }
        }

        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && vis[i][0]==0){
                dfs(board,vis,i,0);
            }
            if(board[i][m-1]=='O' && vis[i][m-1]==0){
                dfs(board,vis,i,m-1);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};