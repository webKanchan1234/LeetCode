class Solution {
public:
    
    int helper(int n,vector<int>& v){
        if(n==1 || n==0){
            return 1;
        }
        if(v[n]!=-1){
            return v[n];
        }
        int onestep=helper(n-1,v);
        int twostep=helper(n-2,v);
        v[n]=onestep+twostep;
        return v[n];
    }
    int climbStairs(int n) {
        vector<int>v(n+1,-1);
        return helper(n,v);
    }
};