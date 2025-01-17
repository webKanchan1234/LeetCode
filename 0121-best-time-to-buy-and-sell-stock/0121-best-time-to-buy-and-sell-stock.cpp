class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=INT_MIN;
        int n=prices.size();
        int stillMin=INT_MAX;
        for(int i=0;i<n;i++){
            stillMin=min(stillMin,prices[i]);
            mx=max(mx,prices[i]-stillMin);
        }
        return mx;
    }
};