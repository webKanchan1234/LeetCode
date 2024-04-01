class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n=words.size();
        int l=allowed.length();
        int cnt=0;
        int res=0;
        map<char,int>m;
        for(auto x:allowed){
            m[x]++;
        }

        for(auto x:words){
            int l=x.length();
            int cnt=0;
            for(int i=0;i<l;i++){
                if(m.find(x[i])!=m.end()){
                    cnt++;
                }else{
                    break;
                }
            }
            if(cnt==l){
                res++;
            }
        }
        return res;
    }
};