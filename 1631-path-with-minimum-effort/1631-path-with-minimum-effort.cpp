class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>q;
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        q.push({0,{0,0}});
        // int diff=0;
        dis[0][0]=0;
        int row[4]={-1,0,1,0};
        int col[4]={0,1,0,-1};

        while(!q.empty()){
            auto top=q.top();
            q.pop();
            int diff=top.first;
            int r=top.second.first;
            int c=top.second.second;
            if(r==n-1 && c==m-1){
                    return diff;
                }
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newdiff=max(abs(heights[r][c]-heights[nr][nc]),diff);
                    if(newdiff<dis[nr][nc]){
                        dis[nr][nc]=newdiff;
                        q.push({newdiff,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};