class Solution {
public:
    int helper(int idx,vector<int>& nums,vector<int>&dp){
        if(idx==0){
            return nums[idx];
        }
        if(idx<0){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int pick=nums[idx]+helper(idx-2,nums,dp);
        int notpic=0+helper(idx-1,nums,dp);
        return dp[idx]=max(pick,notpic);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(n-1,nums,dp);
    }
};