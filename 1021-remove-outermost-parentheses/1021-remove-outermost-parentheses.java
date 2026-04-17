class Solution {
    public String removeOuterParentheses(String s) {
        int n=s.length();
        int cnt=0;
        int start=0;

        List<String> str=new ArrayList<>();

        for(int i=0;i<n;i++){
            char ch=s.charAt(i);

            if(ch=='('){
                cnt++;
            }else{
                cnt--;
            }

            if(cnt==0){
                str.add(s.substring(start,i+1));
                start=i+1;
            }
        }

        StringBuilder sb=new StringBuilder();
        for(String st:str){
            sb.append(st.substring(1,st.length()-1));
        }

        return sb.toString();
    }
}