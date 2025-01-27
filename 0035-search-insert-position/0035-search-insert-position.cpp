class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int h=nums.size()-1;
        int n=h;
        int l=0;
        while(l<=h){
            int m=(h+l)/2;
            if(nums[m]==target){
                return m;
            }else if(nums[m]>target){
                h=m-1;
            }else {
                l=m+1;
            }
        }
        return l;
    }
};