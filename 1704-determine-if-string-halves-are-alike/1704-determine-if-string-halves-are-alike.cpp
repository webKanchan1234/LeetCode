class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        string s1=s.substr(0,n/2);
        string s2=s.substr(n/2,n-n/2);
        int cnt1=0,cnt2=0;
        for(int i=0;i<s1.length();i++){
            char c=toupper(s1[i]);
            if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                cnt1++;
            }
        }
        for(int i=0;i<s2.length();i++){
            char c=toupper(s2[i]);
            if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                cnt2++;
            }
        }
        if(cnt1==cnt2){
            return true;
        }
        return false;
    }
};