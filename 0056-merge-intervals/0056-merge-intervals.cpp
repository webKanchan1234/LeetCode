class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            int currst=intervals[i][0];
            int currend=intervals[i][1];
            if(currst>ans.back()[1]){
                ans.push_back(intervals[i]);
                
            }else{
                ans.back()[1]=max(ans.back()[1],currend);
            }
        }
        return ans;
    }
};