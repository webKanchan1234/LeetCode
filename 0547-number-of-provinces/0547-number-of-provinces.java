class Solution {
    public void bfs(int city,int[][] isConnected,boolean[] isvis){
        Queue<Integer>q=new LinkedList<>();
        q.offer(city);
        isvis[city]=true;

        while(!q.isEmpty()){
            int c=q.poll();
            for(int j=0;j<isConnected.length;j++){
                if(isConnected[c][j]==1 && !isvis[j]){
                    isvis[j]=true;
                    q.offer(j);
                }
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
                bfs(i,isConnected,isvis);
            }
        }
        return ans;
    }
}