class Solution {
public:
vector<string>res;
    void generate(int n,int open,int close, string cur){
        if(cur.length()==2*n){
            res.push_back(cur);
            return;
        }
        if(open<n){
            generate(n,open+1,close,cur+"(");
        }
        if(close<open){
            generate(n,open,close+1,cur+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        
        generate(n,0,0,"");
        return res;
    }
};