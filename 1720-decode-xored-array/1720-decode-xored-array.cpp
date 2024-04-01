class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ans;
        ans.push_back(first);
        int n=encoded.size();
        int prev=first;
        for(int i=0;i<n;i++){
            int xr=prev^encoded[i];
            ans.push_back(xr);
            prev=xr;
        }
        return ans;
    }
};