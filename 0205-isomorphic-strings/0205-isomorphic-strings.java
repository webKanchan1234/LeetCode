class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length()){
            return false;
        }
        int[] st=new int[256];
        int[] ts=new int[256];

        for(int i=0;i<s.length();i++){
            if(st[s.charAt(i)]!=ts[t.charAt(i)]){
                return false;
            }

            st[s.charAt(i)]++;
            ts[t.charAt(i)]++;
        }

        return true;

    }
}