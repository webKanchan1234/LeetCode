class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.length();
        int idx=word.find(ch);
        string ans="";
        for(int i=idx;i>=0;i--){
            ans+=word[i];
        }
        for(int i=idx+1;i<n;i++){
            ans+=word[i];
        }
        return ans;
    }
};