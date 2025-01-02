class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]){
            return -1;
        }
        int n=grid.size();
        int m=grid[0].size();
        if(n==1){
            return 1;
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vector<vector<int>>vis(n,vector<int>(m,1e9));
        vis[0][0]=0;
        int dr[8]={ -1, -1, -1, 0, 0, 1, 1, 1 };
        int dc[8]={ -1, 0, 1, -1, 1, -1, 0, 1 };
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int dis=curr.first;
            int cr=curr.second.first;
            int cc=curr.second.second;
            for(int i=0;i<8;i++){
                int nr=cr+dr[i];
                int nc=cc+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && dis+1<vis[nr][nc]){
                    
                    vis[nr][nc]=1+dis;
                    if(nr==n-1 && nc==m-1){
                        return dis+1;
                    }
                    q.push({dis+1,{nr,nc}});
                }
            }
        }
        return -1;
    }
};