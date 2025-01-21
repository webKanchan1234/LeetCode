class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>m;
        m[0]=1;
        int ans=0;
        int presum=0;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int diff=presum-k;
            ans +=m[diff];
            m[presum] +=1;
        }
        return ans;
    }
};