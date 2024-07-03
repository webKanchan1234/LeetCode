class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<=4){
            return 0;
        }
        int ans=INT_MAX;
        for(int i=0;i<=3;i++){
            ans=min(ans,(nums[n-4+i]-nums[i]));
        }
        return ans;
    }
};