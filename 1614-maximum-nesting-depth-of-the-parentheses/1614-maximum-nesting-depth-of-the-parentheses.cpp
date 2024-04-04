class Solution {
public:
    int maxDepth(string s) {
        int mx=0;
        int cnt=0;
        for(auto x:s){
            if(x=='('){
                cnt++;
                mx=max(mx,cnt);
            }else if(x==')'){
                cnt--;
            }else{
                continue;
            }
        }
        return mx;
    }
};