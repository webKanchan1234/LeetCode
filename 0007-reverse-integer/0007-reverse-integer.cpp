class Solution {
public:
    int reverse(int x) {
        long div=0;
        bool flag=false;
        // if(x<0){
        //     flag=true;
        //     x=-x;
        // }
        while(x){
            if(div<INT_MIN/10 || div>INT_MAX/10){
            return 0;
        }
            long r=x%10;
            div=div*10+r;
            x/=10;
        }
        if(flag){
            div=-div;
        }
        if(div<INT_MIN || div>INT_MAX){
            return 0;
        }
        return int(div);
    }
};