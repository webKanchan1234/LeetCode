class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xr=0;
        for(auto x:nums){
            xr^=x;
        }
        int cnt=0;
        while(k|| xr){
            if((k%2)!=(xr%2)){
                cnt++;
            }
            k/=2;
            xr/=2;
        }
        return cnt;
    }
};