class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int mx=0;
        for(auto x:nums){
            if(x==1){
                cnt++;
                mx=max(mx,cnt);
            }else{
                
                cnt=0;
            }
        }
        return mx;
    }
};