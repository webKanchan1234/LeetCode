class Solution {
public:
    int freq[1001];
    int totalbeautifulsubset(vector<int>& nums,int i, int k){
        if(i==nums.size()){
            return 1;
        }
        int taken=0;
        if(nums[i]-k<0 || freq[nums[i]-k]==0){
            freq[nums[i]]++;
            taken=totalbeautifulsubset(nums,i+1,k);
            freq[nums[i]]--;
        }
        int nottaken=totalbeautifulsubset(nums,i+1,k);
        return taken+nottaken;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        memset(freq,0,sizeof(nums));
        return totalbeautifulsubset(nums,0,k)-1;
        
    }
};