class Solution {
    public boolean bipart(int st,int[] color,int[][] graph){
        Queue<Integer>q=new LinkedList<>();
        q.offer(st);
        color[st]=0;

        while(!q.isEmpty()){
            int node=q.poll();

            for(int nxt:graph[node]){
                if(color[nxt]==-1){
                    color[nxt]=1-color[node];
                    q.offer(nxt);
                }else if(color[nxt]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int n=graph.length;
        int[] color=new int[n];

        Arrays.fill(color,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bipart(i,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
}