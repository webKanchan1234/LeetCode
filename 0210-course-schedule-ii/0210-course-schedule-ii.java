class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj=new ArrayList<>();
        for(int i=0;i<numCourses;i++){
            adj.add(new ArrayList<>());
        }

        int[] indeg=new int[numCourses];

        for(int[] pre:prerequisites){
            int c=pre[0];
            int r=pre[1];
            adj.get(r).add(c);
            indeg[c]++;
        }

        Queue<Integer>q=new LinkedList<>();

        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.offer(i);
            }
        }

        int[] ans=new int[numCourses];
        int i=0;

        while(!q.isEmpty()){
            int curr=q.poll();
            ans[i]=curr;
            i++;

            for(int next : adj.get(curr)){
                indeg[next]--;
                if(indeg[next]==0){
                    q.offer(next);
                }
            }
        }

        return i == numCourses ? ans : new int[0];
    }
}