class Solution {
public:
    void dfs(int node,int n,vector<vector<int>>& isConnected,vector<int>& vis ){
        vis[node]=1;
        for(int i=0;i<n;i++){
            if(isConnected[node][i] && !vis[i]){
                dfs(i,n,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,n,isConnected,vis);
            }
        }
        return cnt;
    }
};