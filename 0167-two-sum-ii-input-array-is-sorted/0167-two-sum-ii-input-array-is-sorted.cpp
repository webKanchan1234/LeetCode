class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int r=numbers.size()-1;
        int l=0;
        while(l<r){
            int sum=numbers[l]+numbers[r];
            if(sum==target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }else if(sum<target){
                l++;
            }else{
                r--;
            }
        }
        
        return ans;
    }
};