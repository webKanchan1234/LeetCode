class Solution {

    public boolean helper(int r,int c,char[][] board,String word,int idx){
        if(idx==word.length()) return true;
        if(r<0 || c<0 || r>=board.length|| c>=board[0].length || board[r][c]!=word.charAt(idx)){
            return false;
        }

        char temp=board[r][c];
        board[r][c]='#';

        boolean found=helper(r+1,c,board,word,idx+1) || helper(r-1,c,board,word,idx+1) || helper(r,c+1,board,word,idx+1) || helper(r,c-1,board,word,idx+1);
        board[r][c]=temp;
        return found;
    }
    public boolean exist(char[][] board, String word) {
        int n=board.length;
        int m=board[0].length;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(helper(i,j,board,word,0)){
                    return true;
                }
            }
        }

        return false;
    }
}