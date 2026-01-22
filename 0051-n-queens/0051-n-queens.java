class Solution {

    public void helper(int r, int n, char[][] board,
                       boolean[] cols, boolean[] d1, boolean[] d2,
                       List<List<String>> ans) {

        if (r == n) {
            List<String> temp = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                temp.add(new String(board[i]));
            }
            ans.add(temp);
            return;
        }

        for (int col = 0; col < n; col++) {

            int diag1 = r - col + n - 1;
            int diag2 = r + col;

            if (cols[col] || d1[diag1] || d2[diag2]) continue;

            board[r][col] = 'Q';
            cols[col] = d1[diag1] = d2[diag2] = true;

            helper(r + 1, n, board, cols, d1, d2, ans);

            board[r][col] = '.';
            cols[col] = d1[diag1] = d2[diag2] = false;
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        char[][] board = new char[n][n];

        boolean[] cols = new boolean[n];
        boolean[] d1 = new boolean[2 * n];
        boolean[] d2 = new boolean[2 * n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }

        helper(0, n, board, cols, d1, d2, ans);
        return ans;
    }
}
