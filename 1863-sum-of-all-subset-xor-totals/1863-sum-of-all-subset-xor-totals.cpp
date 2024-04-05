class Solution {
public:
    vector<vector<int>>v;
    void subset(vector<int> nums,int i,int n,vector<int>t){
        if(i==n){
            v.push_back(t);
            return;
        }
        t.push_back(nums[i]);
        subset(nums,i+1,n,t);
        t.pop_back();
        subset(nums,i+1,n,t);
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>t;
        subset(nums,0,n,t);
        int ans=0;
        t.clear();
        for(auto x:v){
            for(auto y:x){
                ans^=y;
            }
            t.push_back(ans);
            ans=0;
        }
        ans=0;
        for(auto x:t){
            ans +=x;
        }
        return ans;
    }
};