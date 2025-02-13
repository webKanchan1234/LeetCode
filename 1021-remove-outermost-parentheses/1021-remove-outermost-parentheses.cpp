class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        string ans;
        int cnt=0;
        for(auto x:s){
            if(x=='('){
                if(cnt>0){
                    ans+=x;
                }
                cnt++;
            }else{
                cnt--;
                if(cnt>0){
                    ans+=x;
                }
            }
            
        }
        return ans;
    }
};