class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int xr=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i=i+2){
            if((nums[i]^nums[i+1])!=0){
                return false;
            }
        }
        return true;
    }
};