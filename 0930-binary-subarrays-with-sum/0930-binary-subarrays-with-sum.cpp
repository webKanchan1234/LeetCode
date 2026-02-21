class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prevsum=0;
        int ans=0;
        unordered_map<int,int>mp({{0,1}});
        for(int i=0;i<nums.size();i++){
            prevsum+=nums[i];
            ans+=mp[prevsum-goal];
            mp[prevsum]++;
        }
        return ans;
    }
};