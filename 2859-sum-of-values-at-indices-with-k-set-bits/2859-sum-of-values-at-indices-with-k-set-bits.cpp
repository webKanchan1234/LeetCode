class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int bits=__builtin_popcount(i);
            if(bits==k){
                sum+=nums[i];
            }
        }
        return sum;
    }
};