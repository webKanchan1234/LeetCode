class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<int[]>> graph=new ArrayList<>();

        for(int i=0;i<=n;i++){
            graph.add(new ArrayList<>());
        }

        for(int[] t:times){
            graph.get(t[0]).add(new int[]{t[1],t[2]});
        }

        int[] dist=new int[n+1];
        Arrays.fill(dist,Integer.MAX_VALUE);

        PriorityQueue<int[]> q=new PriorityQueue<>((a,b)->a[1]-b[1]);
        q.offer(new int[]{k,0});
        dist[k]=0;

        while(!q.isEmpty()){
            int[] curr=q.poll();
            int node=curr[0];
            int tm=curr[1];

            if(tm>dist[node]) continue;

            for(int[] nei:graph.get(node)){
                int nxt=nei[0];
                int t=nei[1];

                if(tm+t<dist[nxt]){
                    dist[nxt]=tm+t;
                    q.offer(new int[]{nxt,dist[nxt]});
                }
            }
        }

        int mx=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==Integer.MAX_VALUE) return -1;
            mx=Math.max(mx,dist[i]);
        }

        return mx;
    }
}