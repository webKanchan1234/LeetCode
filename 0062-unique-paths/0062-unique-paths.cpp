class Solution {
public:
    int unique(int m, int n){
        if(m==1 && n==1){
            return 1;
        }
        if(m<0 || n<0){
            return 0;
        }
        int up=unique(m,n-1);
        int left=unique(m-1,n);
        return up+left;
    }
    int uniquePaths(int m, int n) {
        return unique(m,n);
    }
};