class Solution {
public:
    vector<vector<int>>ans;
    void subset(vector<int>& nums,int i,int n,vector<int>& v){
        if(i==n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        subset(nums,i+1,n,v);
        v.pop_back();
        subset(nums,i+1,n,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        subset(nums,0,n,v);
        return ans;
    }
};