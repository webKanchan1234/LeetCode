class Solution {
    public int numberOfSubstrings(String s) {
        int n=s.length();

        int l=0;
        int r=0;
        int ans=0;
        int[] mp=new int[3];

        while(r<n){
            mp[s.charAt(r)-'a']++;
            while(mp[0]>0 && mp[1]>0 && mp[2]>0){
                ans+=n-r;
                mp[s.charAt(l)-'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
}