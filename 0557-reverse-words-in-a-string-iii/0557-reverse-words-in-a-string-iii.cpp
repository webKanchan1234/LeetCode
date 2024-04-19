class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string ans="";
        string w="";
        while(str>>w){
            reverse(w.begin(),w.end());
            ans+=w+" ";
        }
        ans.pop_back();
        return ans;
    }
};