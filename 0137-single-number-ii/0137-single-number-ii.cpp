class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        int ans=0;
        for(auto x:nums){
            
            ans^=x;
            // cout<<ans<<" ";
        }
    for(auto x:m){
        if(x.second>1){
            ans^=x.first;
            // break;
        }
    }
        return ans;
    }
};