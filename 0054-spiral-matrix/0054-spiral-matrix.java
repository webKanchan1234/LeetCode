class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int top=0;
        int but=matrix.length-1;
        int left=0;
        int right=matrix[0].length-1;

        List<Integer> ans=new ArrayList<>();

        while(top<=but && left<=right){

            for(int i=left;i<=right;i++){
                ans.add(matrix[top][i]);
            }
            top++;

            for(int i=top;i<=but;i++){
                ans.add(matrix[i][right]);
            }
            right--;

            if(top<=but){
                for(int i=right;i>=left;i--){
                    ans.add(matrix[but][i]);
                }
                but--;
            }

            if(left<=right){
                for(int i=but;i>=top;i--){
                    ans.add(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
}