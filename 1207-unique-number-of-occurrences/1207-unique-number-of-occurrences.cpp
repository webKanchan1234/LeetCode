class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        for(auto x:arr){
            m[x]++;
        }
        set<int>s;
        for(auto x:m){
            if(s.find(x.second)!=s.end()){
                return false;
            }
            s.insert(x.second);
        }
        
        return true;
    }
};