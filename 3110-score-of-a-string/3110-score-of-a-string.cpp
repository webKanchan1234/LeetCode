class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        int n=s.length();
        for(int i=1;i<n;i++){
            ans+=abs((s[i]-'0')-(s[i-1]-'0'));
        }
        return ans;
    }
};