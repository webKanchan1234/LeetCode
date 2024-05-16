class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int open=0;
        for(auto x:s){
            if(x=='(' && open++ > 0){
                ans+=x;
            }
            if(x==')' && open-- > 1){
                ans+=x;
            }
        }
        return ans;
    }
};