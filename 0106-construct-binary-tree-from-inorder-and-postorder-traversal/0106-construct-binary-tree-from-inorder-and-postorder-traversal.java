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
    int idx;
    Map<Integer,Integer> m=new HashMap<>();

    public TreeNode build(int[] postorder,int l,int r){
        if(l>r){
            return null;
        }

        int root=postorder[idx--];
        TreeNode rootV=new TreeNode(root);

        int rootidx=m.get(root);

        rootV.right=build(postorder,rootidx+1,r);
        rootV.left=build(postorder,l,rootidx-1);

        return rootV;

    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        idx=postorder.length-1;
        for(int i=0;i<inorder.length;i++){
            m.put(inorder[i],i);
        }

        return build(postorder,0,inorder.length-1);
    }
}