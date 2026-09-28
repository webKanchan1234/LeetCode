class Solution {
    public void dfs(int[][] isConnected,int i,boolean[] visited){
        visited[i]=true;

        for(int next=0;next<isConnected.length;next++){
            if(isConnected[i][next]==1 && !visited[next]){
                dfs(isConnected,next,visited);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n=isConnected.length;
        int cnt=0;

        boolean[] visited=new boolean[n];

        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(isConnected,i,visited);
            }
        }

        return cnt;
    }
}