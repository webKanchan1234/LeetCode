class Solution {

    public int expand(String s,int l,int h){
        while(l>=0 && h<s.length() && s.charAt(l)==s.charAt(h)){
            l--;
            h++;
        }

        return h-l-1;
    }
    public String longestPalindrome(String s) {
        int n=s.length();
        int start=0;
        int end=0;
        int ans=0;

        for(int i=0;i<n;i++){
            int oddlen=expand(s,i,i);
            int evenlen=expand(s,i,i+1);

            ans=Math.max(oddlen,evenlen);

            if(ans>end-start){
                start=i-(ans-1)/2;
                end=i+ans/2;
            }
        }
        return s.substring(start,end+1);
    }
}