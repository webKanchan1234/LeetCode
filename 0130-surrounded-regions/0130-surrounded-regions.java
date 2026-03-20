class Solution {
    
    public void solve(char[][] board) {
        int n=board.length;
        int m=board[0].length;
        Queue<int[]>q=new LinkedList<>();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.offer(new int[]{i,0});
            }
            if(board[i][m-1]=='O'){
                q.offer(new int[]{i,m-1});
            }
        }

        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.offer(new int[]{0,i});
            }
            if(board[n-1][i]=='O'){
                q.offer(new int[]{n-1,i});
            }
        }

        int[] ax={-1,1,0,0};
        int[] ay={0,0,1,-1};

        while(!q.isEmpty()){
            int[] cell=q.poll();
            int r=cell[0];
            int c=cell[1];
            if(r<0 || c<0 || r>=n || c>=m || board[r][c]!='O') continue;

            board[r][c]='#';
            for(int i=0;i<4;i++){
                int x=r+ax[i];
                int y=c+ay[i];
                q.offer(new int[]{x,y});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }

        }
        
    }
}