class Solution {
public:
    int binary(vector<int>& nums, int target, bool flag){
        int l=0;
        int r=nums.size()-1;
        int idx=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                idx=m;
                if(flag){
                    r=m-1;
                    
                }else{
                    l=m+1;
                }
            }else if(nums[m]<target){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size();
        int first=binary(nums,target,true);
        int last=binary(nums,target,false);
        return {first,last};
    }
};