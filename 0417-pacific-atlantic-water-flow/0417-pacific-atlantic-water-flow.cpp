class Solution {
public:
    void func(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<int>>& oceans){
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size()){
            return;
        }
        if(oceans[i][j]==1){
            return;
        }
        if(heights[i][j]<prev){
            return;
        }
        oceans[i][j]=1;
        func(heights,i-1,j,heights[i][j],oceans);
        func(heights,i+1,j,heights[i][j],oceans);
        func(heights,i,j+1,heights[i][j],oceans);
        func(heights,i,j-1,heights[i][j],oceans);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>ans;
        if(n<1){
            return ans;
        }
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> altantic(n,vector<int>(m,0));

        // for top pacific and button altantic
        for(int i=0;i<m;i++){
            func(heights,0,i,INT_MIN,pacific);
            func(heights,n-1,i,INT_MIN,altantic);
        }

        // for left pacific and right altantic
        for(int i=0;i<n;i++){
            func(heights,i,0,INT_MIN,pacific);
            func(heights,i,m-1,INT_MIN,altantic);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==altantic[i][j]){
                    vector<int>v(2);
                    v[0]=i;
                    v[1]=j;
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};