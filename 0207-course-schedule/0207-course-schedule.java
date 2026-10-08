class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph=new ArrayList<>();
        int[] indegree=new int[numCourses];

        for(int i=0;i<numCourses;i++){
            graph.add(new ArrayList<>());
        }

        for(int[] pre:prerequisites){
            int course=pre[0];
            int preq=pre[1];
            graph.get(preq).add(course);

            indegree[course]++;
        }

        Queue<Integer> q=new LinkedList<>();

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.offer(i);
            }
        }

        int complete=0;

        while(!q.isEmpty()){
            complete++;
            int course=q.poll();

            for(int nxt:graph.get(course)){
                indegree[nxt]--;

                if(indegree[nxt]==0){
                    q.offer(nxt);
                }
            }
        }

        return complete==numCourses;
    }
}