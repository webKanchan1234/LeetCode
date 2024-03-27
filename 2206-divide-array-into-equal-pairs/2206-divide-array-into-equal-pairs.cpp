class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        if(n%2!=0){
            return false;
        }
        for(auto x:nums){
            m[x]++;
        }
        for(auto x:m){
            if(x.second%2!=0){
                return false;
            }
        }
        return true;
    }
};