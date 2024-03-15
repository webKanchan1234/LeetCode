class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int cnt0=0;
        int prod=1;
        vector<int> ans(n,0);
        for(auto x:nums){
            if(x==0){
                cnt0++;
            }
            if(x!=0){
                prod*=x;
            }
        }
        if(cnt0>1){
            return ans;
        }
        ans.clear();
        for(auto x:nums){
            if(x!=0 && cnt0==0){
                int v=prod/x;
                ans.push_back(v);
            }else if(x!=0 && cnt0==1){
                ans.push_back(0);
            }else if(x==0){
                ans.push_back(prod);
            }
        }
        return ans;
    }
};