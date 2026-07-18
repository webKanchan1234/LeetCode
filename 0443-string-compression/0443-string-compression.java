class Solution {
    public int compress(char[] chars) {
        int n=chars.length;
        int idx=0;
        int i=0;

        while(i<n){
            char ch=chars[i];
            int cnt=0;
            while(i<n && ch==chars[i]){
                i++;
                cnt++;
            }

            chars[idx++]=ch;
            if(cnt>1){
                String sb=String.valueOf(cnt);
                for(char c:sb.toCharArray()){
                    chars[idx++]=c;
                }
            }
        }
        return idx;
    }
}