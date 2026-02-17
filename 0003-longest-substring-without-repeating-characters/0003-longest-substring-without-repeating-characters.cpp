class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        map<char,int>mp;
        int res=0;
        int start=0;
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                start=max(start,mp[s[i]]+1);
            }
            mp[s[i]]=i;
            maxlen=max(maxlen,i-start+1);
        }
        return maxlen;
    }
};