class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       map<int,int>m;
       for(auto x:nums){
        m[x]++;
       }
       for(int i=1;i<=nums.size();i++){
        if(m.find(i)!=m.end()){
            continue;
        }else{
            return i;
        }
       }
       return nums.size()+1;
    }
};