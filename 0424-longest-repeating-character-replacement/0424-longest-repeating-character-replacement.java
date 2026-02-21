class Solution {
    public int characterReplacement(String s, int k) {
        int n=s.length();
        int mx=0;
        int mxFr = 0;
        int[] freq=new int[26];
        int l=0;

        for(int r=0;r<n;r++){
            freq[s.charAt(r)-'A']++;
            mxFr=Math.max(mxFr,freq[s.charAt(r)-'A']);

            while((r-l+1)-mxFr>k){
                freq[s.charAt(l)-'A']--;
                l++;
            }
            mx=Math.max(mx,r-l+1);
        }
        return mx;
    }
}