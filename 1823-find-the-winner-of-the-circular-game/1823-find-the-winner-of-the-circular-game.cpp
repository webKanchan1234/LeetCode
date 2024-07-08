class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        int idx=0;
        while(v.size()>1){
            int nxtidx=(idx+k-1)%v.size();
            v.erase(v.begin()+nxtidx);
            idx=nxtidx;
        }
        return v[0];
    }
};