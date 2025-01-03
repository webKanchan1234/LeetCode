class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        int temp[n];
        int fromRight=n-k;
        if(k>n){
            fromRight=k%n;
        }
        for (int i = 0; i < n; i++) {
            temp[i]=nums[(i+fromRight)%n];
        }
        for (int i = 0; i < n; i++) {
            nums[i]=temp[i];
        }
    }
};