class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n=graph.length;
        int[] indeg=new int[n];

        List<List<Integer>> rev=new ArrayList<>();
        for(int i=0;i<n;i++){
            rev.add(new ArrayList<>());
        }

        for(int i=0;i<n;i++){
            for(int nei:graph[i]){
                rev.get(nei).add(i);
                indeg[i]++;
            }
        }

        Queue<Integer> q=new LinkedList<>();

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.offer(i);
            }
        }

        boolean[] safe = new boolean[n];
        List<Integer> ans=new ArrayList<>();

        int idx=0;

        while(!q.isEmpty()){
            int node=q.poll();
            safe[node]=true;

            for(int nei:rev.get(node)){
                indeg[nei]--;
                if(indeg[nei]==0){
                    q.offer(nei);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (safe[i]) ans.add(i);
        }
        return ans;
    }
}