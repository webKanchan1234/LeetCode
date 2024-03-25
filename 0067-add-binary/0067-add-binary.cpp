class Solution {
public:
    string addBinary(string a, string b) {
        int i=0;
        int j=0;
        int al=a.length()-1;
        int bl=b.length()-1;
        string ans;
        int c=0;
        while(al>=0 || bl>=0 || c){
            if(al>=0){
                c+=a[al--]-'0';
            }
            if(bl>=0){
                c+=b[bl--]-'0';
            }
            ans+=c%2+'0';
            c/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};