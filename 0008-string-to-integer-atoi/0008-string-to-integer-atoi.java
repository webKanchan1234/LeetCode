class Solution {
    public int myAtoi(String s) {
        int ans=0;
        int n=s.length();

        int i=0;
        while(i<n && s.charAt(i)==' ') i++;

        int sign=1;
        if (i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            if (s.charAt(i) == '-') sign = -1;
            i++;
        }

        

        while(i<n && Character.isDigit(s.charAt(i))){
            int dig=s.charAt(i)-'0';

            if (ans > (Integer.MAX_VALUE - dig) / 10) {
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            
            ans = ans * 10 + dig;
            i++;
        }

        return ans*sign;
    }
}