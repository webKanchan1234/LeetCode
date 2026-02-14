class Solution {
    public long maxsub(int[] arr){
        int n=arr.length;
        Stack<Integer> s=new Stack<>();

        long sum=0;

        long[] left=new long[n];
        long[] right=new long[n];

        for(int i=0;i<n;i++){
            while(!s.isEmpty() && arr[s.peek()]<arr[i]){
                s.pop();
            }

            left[i]=s.isEmpty() ? i+1 : i-s.peek();
            s.push(i);
        }

        s.clear();

        for(int i=n-1;i>=0;i--){
            while(!s.isEmpty() && arr[s.peek()]<=arr[i]){
                s.pop();
            }

            right[i]=s.isEmpty() ? n-i : s.peek()-i;
            s.push(i);
        }


        for(int i=0;i<n;i++){
            sum+=(arr[i]*left[i]*right[i]);
        }
        return sum;
    }

    public long minsub(int[] arr){
        int n=arr.length;
        Stack<Integer> s=new Stack<>();

        long sum=0;
        long[] left=new long[n];
        long[] right=new long[n];

        for(int i=0;i<n;i++){
            while(!s.isEmpty() && arr[s.peek()]>arr[i]){
                s.pop();
            }

            left[i]=s.isEmpty() ? i+1 : i-s.peek();
            s.push(i);
        }

        s.clear();

        for(int i=n-1;i>=0;i--){
            while(!s.isEmpty() && arr[s.peek()]>=arr[i]){
                s.pop();
            }

            right[i]=s.isEmpty() ? n-i : s.peek()-i;
            s.push(i);
        }

        for(int i=0;i<n;i++){
            sum+=(arr[i]*left[i]*right[i]);
        }
        return sum;
    }
    public long subArrayRanges(int[] nums) {
        return maxsub(nums)-minsub(nums);
    }
}