class Solution {
public:
    vector<vector<int>>ans;
    void combination(vector<int>& nums,int tar, int i,vector<int>& v){
        if(tar==0){
            ans.push_back(v);
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            if(nums[j]>tar) break;
            v.push_back(nums[j]);
            combination(nums,tar-nums[j],j+1,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>v;
        combination(candidates,target,0,v);
        
        return ans;
    }
};