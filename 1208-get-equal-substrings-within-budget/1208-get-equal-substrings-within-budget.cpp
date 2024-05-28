class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int left=0;
        int window=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            window+=abs(s[i] - t[i]);
            while(window>maxCost){
                window-=abs(s[left] - t[left]);
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};