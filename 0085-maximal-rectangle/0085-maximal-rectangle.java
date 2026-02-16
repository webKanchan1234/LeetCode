class Solution {
    public int helper(int[] arr){
        int n=arr.length;
        Stack<Integer>s=new Stack<>();
        int mx=0;
        for(int i=0;i<=n;i++){
            int h=(i==n) ? 0 : arr[i];
            while(!s.isEmpty() &&  arr[s.peek()]>h){
                int he=arr[s.pop()];
                int w=s.isEmpty() ? i : i - s.peek() - 1;
                mx = Math.max(mx, he * w);
            }
            s.push(i);
        }
        return mx;
    }
    public int maximalRectangle(char[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;

        int[] arr=new int[m];
        Arrays.fill(arr,0);
        int mxarea=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    arr[j]++;
                }else{
                    arr[j]=0;
                }
            }
            int area=helper(arr);
        mxarea=Math.max(area,mxarea);
        }

        
        
        return mxarea;
    }
}