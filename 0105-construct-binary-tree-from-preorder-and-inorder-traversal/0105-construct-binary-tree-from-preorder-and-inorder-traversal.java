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
    int idx=0;
    Map<Integer,Integer> m=new HashMap<>();

    public TreeNode build(int[] preorder,int l,int r){
        if(l>r){
            return null;
        }

        int root=preorder[idx++];
        TreeNode rootV=new TreeNode(root);

        int rootidx=m.get(root);

        rootV.left=build(preorder,l,rootidx-1);
        rootV.right=build(preorder,rootidx+1,r);

        return rootV;

    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        
        for(int i=0;i<inorder.length;i++){
            m.put(inorder[i],i);
        }

        return build(preorder,0,inorder.length-1);
    }
}