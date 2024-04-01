class Solution {
public:
    int fib(int n) {
        int f=0;
        int s=1;
        int ans=0;
        if(n==0){
            return 0;
        }
        if(n<=2){
            return 1;
        }
        for(int i=2;i<=n;i++){
            ans=f+s;
            f=s;
            s=ans;
        }
        return ans;
    }
};