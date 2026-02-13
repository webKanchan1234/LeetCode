class Solution {
    public int sumSubarrayMins(int[] arr) {
        int n=arr.length;
        int mod=1_000_000_007;

        long[] left=new long[n];
        long[] right=new long[n];

        Stack<Integer> s=new Stack<>();

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
            right[i]=s.isEmpty() ? n-i :s.peek()-i;
            s.push(i);
        }

        long ans=0;

        for(int i=0;i<n;i++){
            ans=(ans+arr[i]*left[i]*right[i])%mod;
        }

        return (int)ans;
    }
}