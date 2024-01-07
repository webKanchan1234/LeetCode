class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        for(char ch:s){
            m[ch]++;
        }
        vector<pair<char,int>>vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), [](const pair<char,int>& a, const pair<char, int>& b) {
        return a.second > b.second;
        });

        string ans;
        for(auto x:vec){
            while(x.second>0){
                ans+=x.first;
                x.second--;
            }
        }
        return ans;
    }
};