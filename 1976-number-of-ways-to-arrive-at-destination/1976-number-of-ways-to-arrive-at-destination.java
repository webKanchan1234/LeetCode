class Solution {
    public int countPaths(int n, int[][] roads) {
        List<List<int[]>> graph=new ArrayList<>();

        for(int i=0;i<n;i++){
            graph.add(new ArrayList<>());
        }

        for(int[] rd:roads){
            graph.get(rd[0]).add(new int[]{rd[1],rd[2]});
            graph.get(rd[1]).add(new int[]{rd[0],rd[2]});
        }

        PriorityQueue<long[]> q=new PriorityQueue<>((a,b)->Long.compare(a[1], b[1]));
        long[] dist=new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);

        int[] ways=new int[n];
        q.offer(new long[]{0,0});

        dist[0]=0;
        ways[0]=1;

        int MOD = (int)1e9 + 7;

        while(!q.isEmpty()){
            long[] curr=q.poll();
            int node=(int)curr[0];
            long tm=curr[1];

            if(tm>dist[node]) continue;

            for(int[] nei:graph.get(node)){
                int nxt=nei[0];
                int t=nei[1];

                if(tm+t<dist[nxt]){
                    dist[nxt]=tm+t;
                    ways[nxt]=ways[node];
                    q.offer(new long[]{nxt,dist[nxt]});
                }else if(tm+t==dist[nxt]){
                    ways[nxt]=(ways[nxt]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
}