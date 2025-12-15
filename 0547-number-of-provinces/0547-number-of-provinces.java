class Solution {
    public void dfs(int city,int[][] isConnected,boolean[] isvis){
        isvis[city]=true;

        for(int i=0;i<isConnected.length;i++){
            if(isConnected[city][i]==1 && !isvis[i]){
                dfs(i,isConnected,isvis);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n=isConnected.length;
        int ans=0;
        boolean[] isvis=new boolean[n];

        for(int i=0;i<n;i++){
            if(!isvis[i]){
                ans++;
                dfs(i,isConnected,isvis);
            }
        }
        return ans;
    }
}