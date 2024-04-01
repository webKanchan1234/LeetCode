class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        stringstream str(s);
        string w;

        while(str>>w);
        return w.length();
    }
};