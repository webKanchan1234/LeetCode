class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=0;
        int h=num;
        while(l<=h){
            long long m=(l+h)/2;
            if(m*m==num){
                return true;
            }else if(m*m<num){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return false;
    }
};