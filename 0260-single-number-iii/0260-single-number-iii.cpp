class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int>ans;
        int xr=0;
        int unique=0;
        for(auto x:nums){
            xr^=x;
            if(xr==0){
                unique=0;
            }else{
                unique=x;
            }
        }
        ans.push_back(unique);
        int v1=xr^unique;
        ans.push_back(v1);
        return ans;
    }
};