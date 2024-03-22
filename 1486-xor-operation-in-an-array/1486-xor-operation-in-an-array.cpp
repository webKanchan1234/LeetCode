class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>v;
        for(int i=0;i<n;i++){
            int t=start+2*i;
            v.push_back(t);
        }
        int ans=0;
        for(auto x:v){
            ans^=x;
        }
        return ans;
    }
};