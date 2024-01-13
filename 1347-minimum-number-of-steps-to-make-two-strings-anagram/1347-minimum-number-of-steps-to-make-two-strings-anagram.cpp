class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26]={0};
        int cnt=0;
        for(char c:s){
            freq[c-'a']++;
        }
        for(char c:t){
            freq[c-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                cnt+=freq[i];
            }
        }
        return cnt;
    }
};