class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        for(auto x:m){
            if(x.second==1){
                return x.first;
            }
        }
        return 0;
    }
};