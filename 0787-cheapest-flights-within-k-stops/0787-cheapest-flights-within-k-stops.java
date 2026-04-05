class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        List<List<int[]>> graph=new ArrayList<>();
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<>());
        }

        for(int[] f:flights){
            graph.get(f[0]).add(new int[]{f[1],f[2]});
        }

        int[] dist=new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);

        Queue<int[]>q=new LinkedList<>();

        q.offer(new int[]{src,0,0});
        
        dist[src] = 0;

        while(!q.isEmpty()){
            int[] curr=q.poll();
            int node=curr[0];
            int cost=curr[1];
            int stop=curr[2];

            if(stop>k){
                continue; 
            }

            for(int[] nei:graph.get(node)){
                int nxt=nei[0];
                int price=nei[1];

                if(cost+price<dist[nxt] && stop<=k){
                    dist[nxt]=cost+price;
                    q.offer(new int[]{nxt,dist[nxt],stop+1});
                }
            }
        }

        return dist[dst]==Integer.MAX_VALUE ? -1 : dist[dst];
    }
}