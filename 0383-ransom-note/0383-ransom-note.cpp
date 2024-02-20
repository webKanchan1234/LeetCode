class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>m;
        for(auto x:magazine){
            m[x]++;
        }
        for(auto x:ransomNote){
            if(m.find(x)!=m.end() && m[x]!=0){
                m[x]--;
            }else{
                return false;
            }
        }
        return true;
    }
};