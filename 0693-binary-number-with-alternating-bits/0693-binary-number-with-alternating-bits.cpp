class Solution {
public:
    bool hasAlternatingBits(int n) {
        int cnt0=0;
        int cnt1=0;
        while(n!=0){
            int bit=n&1;
            if(bit==1){
                cnt1++;
                cnt0=0;
            }else{
                cnt0++;
                cnt1=0;
            }
            n=n>>1;
            if(cnt0==2 || cnt1==2){
                return false;
            }
        }
        return true;
    }
};