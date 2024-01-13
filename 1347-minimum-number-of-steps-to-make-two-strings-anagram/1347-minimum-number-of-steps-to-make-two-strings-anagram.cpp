class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>m1;
        map<char,int>m2;
        int cnt=0;
        for(auto x:s){
            m1[x]++;
        }
        for(auto x:t){
            m2[x]++;
        }
        sort(t.begin(),t.end());
        for(auto x:t){
            if(m1.find(x)!=m1.end()){
                if(m1[x]>0){
                    m1[x]--;
                }else{
                    cnt++;
                }
                
            }else{
                cnt++;
            }
        }
        return cnt;
    }
};