/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public void parentmap(TreeNode root,TreeNode parent,Map<TreeNode,TreeNode> m){
        if(root==null){
            return;
        }

        m.put(root,parent);
        parentmap(root.left,root,m);
        parentmap(root.right,root,m);
    }
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<TreeNode,TreeNode> m=new HashMap<>();

        parentmap(root,null,m);
        Queue<TreeNode> q=new LinkedList<>();
        Set<TreeNode> vis=new HashSet<>();

        q.offer(target);
        vis.add(target);

        int dist=0;

        while(!q.isEmpty()){
            int sz=q.size();

            if(dist==k) break;

            for(int i=0;i<sz;i++){
                TreeNode curr=q.poll();

                if(curr.left!=null && !vis.contains(curr.left)){
                    vis.add(curr.left);
                    q.offer(curr.left);
                }

                if(curr.right!=null && !vis.contains(curr.right)){
                    vis.add(curr.right);
                    q.offer(curr.right);
                }

                TreeNode par=m.get(curr);
                if(par!=null && !vis.contains(par)){
                    vis.add(par);
                    q.offer(par);
                }
            }
            dist++;
        }

        List<Integer> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            ans.add(q.poll().val);
        }

        return ans;

    }
}