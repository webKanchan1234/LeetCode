/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeMap<Integer,TreeMap<Integer,PriorityQueue<Integer>>> q=new TreeMap<>();

    public void dfs(TreeNode root,int x,int y){
        if(root==null){
            return;
        }

        q.putIfAbsent(x,new TreeMap<>());
        q.get(x).putIfAbsent(y,new PriorityQueue<>());
        q.get(x).get(y).offer(root.val);

        dfs(root.left,x-1,y+1);
        dfs(root.right,x+1,y+1);
    }
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        dfs(root,0,0);

        List<List<Integer>> ans=new ArrayList<>();

        for(TreeMap<Integer,PriorityQueue<Integer>> pq:q.values()){
            List<Integer> li=new ArrayList<>();

            for(PriorityQueue<Integer> node: pq.values()){
                while(!node.isEmpty()){
                    li.add(node.poll());
                }
            }
            ans.add(li);
        }
        return ans;
    }
}