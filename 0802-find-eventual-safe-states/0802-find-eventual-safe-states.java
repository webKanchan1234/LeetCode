class Solution {
    public boolean dfs(int node, int[][] graph, int[] vis, int[] path, int[] check) {
        vis[node] = 1;
        path[node] = 1;
        check[node] = 0;

        for (int next : graph[node]) {
            if (vis[next] == 0) {
                if (dfs(next, graph, vis, path, check) == true) {
                    return true;
                }

            } else if (path[next] == 1) {
                return true;
            }
        }
        check[node] = 1;
        path[node] = 0;
        return false;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        int[] vis = new int[n];
        int[] path = new int[n];
        int[] check = new int[n];

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, graph, vis, path, check);
            }
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < check.length; i++) {
            if (check[i] == 1) {
                ans.add(i);
            }
        }

        return ans;
    }
}