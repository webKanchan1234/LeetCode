class Solution {
    public int[] PSE(int[] arr){
        Stack<Integer>s=new Stack<>();

        int[] left=new int[arr.length];

        for(int i=0;i<arr.length;i++){

            while(!s.isEmpty() && arr[s.peek()]>=arr[i]){
                s.pop();
            }
            left[i]=s.isEmpty() ? -1 : s.peek();

            s.push(i);
        }

        return left;
    }

    public int[] NSE(int[] arr){
        Stack<Integer>s=new Stack<>();

        int[] right=new int[arr.length];

        for(int i=arr.length-1;i>=0;i--){

            while(!s.isEmpty() && arr[s.peek()]>=arr[i]){
                s.pop();
            }
            right[i]=s.isEmpty() ? arr.length : s.peek();

            s.push(i);
        }
        return right;
    }
    public int largestRectangleArea(int[] heights) {
        int n=heights.length;
        int[] left=new int[n];
        int[] right=new int[n];

        int[] pse=PSE(heights);
        int[] nse=NSE(heights);

        int mx=0;
        for(int i=0;i<n;i++){
            mx=Math.max(mx,heights[i]*(nse[i]-pse[i]-1));
        }
        return mx;
    }
}