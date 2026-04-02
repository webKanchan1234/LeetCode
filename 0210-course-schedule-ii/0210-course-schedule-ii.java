class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int n=numCourses;
        List<List<Integer>> graph=new ArrayList<>();
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<>());
        }

        int[] indeg=new int[numCourses];

        for(int[] pre:prerequisites){
            graph.get(pre[1]).add(pre[0]);
            indeg[pre[0]]++;
        }

        Queue<Integer>q=new LinkedList<>();
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.offer(i);
            }
        }

        int[] ans=new int[numCourses];
        int idx=0;

        while(!q.isEmpty()){
            int node=q.poll();
            ans[idx++]=node;

            for(int nxt : graph.get(node)){
                indeg[nxt]--;
                if(indeg[nxt]==0){
                    q.offer(nxt);
                }
            }
        }

        if(idx!=numCourses){
            return new int[0];
        }

        return ans;
    }
}