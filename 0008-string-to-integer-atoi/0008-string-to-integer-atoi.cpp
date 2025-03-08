class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            char c=s[i];
            ans=ans*10+ (int)c;
            if(ans>INT_MAX){
                return INT_MIN;
            }else{
                return INT_MAX;
            }
        }
        return ans;
    }
};