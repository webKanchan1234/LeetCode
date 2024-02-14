class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans(n);
        int pos=0;
        int neg=1;
        for(auto x:nums){
            if(x<0){
                ans[neg]=x;
                neg+=2;
            }else{
                ans[pos]=x;
                pos+=2;
            }
        }
        
        return ans;
    }
};