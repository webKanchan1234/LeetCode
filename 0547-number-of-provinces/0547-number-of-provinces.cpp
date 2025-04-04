class Solution {
public:
    // void dfs(int node,int n,vector<vector<int>>& isConnected,vector<int>& vis ){
    //     vis[node]=1;
    //     for(int i=0;i<n;i++){
    //         if(isConnected[node][i] && !vis[i]){
    //             dfs(i,n,isConnected,vis);
    //         }
    //     }
    // }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        vector<int>adj[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // vector<int>vis(n,0);
        int ans=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(!vis[it]){
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};