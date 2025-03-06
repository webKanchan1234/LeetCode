class Solution {
public:
    int helper(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int nottake=0+prev;
            int c=max(take,nottake);

            prev2=prev;
            prev=c;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>v1,v2;
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(i!=0){
                v1.push_back(nums[i]);
            }
            if(i!=n-1){
                v2.push_back(nums[i]);
            }
        }
        int mx1=helper(v1);
        int mx2=helper(v2);
        return max(mx1,mx2);
    }
};