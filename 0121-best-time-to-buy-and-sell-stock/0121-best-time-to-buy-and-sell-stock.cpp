class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        stack<int>s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(prices[i]);
            }else{
                if(prices[i]>s.top()){
                    ans=max(ans,prices[i]-s.top());
                }else{
                    while(!s.empty() && s.top()>prices[i]){
                        s.pop();
                    }
                    s.push(prices[i]);
                }
            }

        }

        return ans;
    }
};