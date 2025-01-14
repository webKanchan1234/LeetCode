class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        for(auto x:m){
            if(x.second>n/2){
                return x.first;
            }
        }
        return 0;
    }
};