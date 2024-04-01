class Solution {
public:
    bool isPowerOfThree(int n) {
        int ans=0;
        if(n==1){
            return true;
        }
        while(n>1){
            if(n%3==0){
                n/=3;
                if(n==1){
                    ans=1;
                }
            }else{
                return false;
            }
            
            
        }
        if(ans==1){
            return true;
        }
        return false;
    }
};