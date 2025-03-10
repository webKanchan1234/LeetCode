class Solution {
public:
    int f(string &s,int i,int sign,long ans){
        if(i>=s.size() || !isdigit(s[i])) return ans*sign;
        ans=ans*10+(s[i]-'0');
        if(sign*ans>INT_MAX) return INT_MAX;
        if(sign*ans<INT_MIN) return INT_MIN;

        return f(s,i+1,sign,ans);

    }
    int myAtoi(string s) {
        long ans = 0;
        int sign = 1;
        int i = 0;
        while (i < s.length() && s[i] == ' ') i++;
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        return f(s,i,sign,ans);
    }
};