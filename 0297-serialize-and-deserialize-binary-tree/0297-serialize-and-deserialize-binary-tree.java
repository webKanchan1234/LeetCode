/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root==null){
            return "";
        }

        StringBuilder sb=new StringBuilder();
        Queue<TreeNode> q=new LinkedList<>();

        q.offer(root);

        while(!q.isEmpty()){
            TreeNode curr=q.poll();
            if(curr==null){
                sb.append("null,");
            }else{
                sb.append(curr.val).append(",");
                q.offer(curr.left);
                q.offer(curr.right);
            }
        }

        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        
        if(data==null || data.isEmpty()){
            return null;
        }

        String[] values=data.split(",");
        TreeNode root=new TreeNode(Integer.parseInt(values[0]));
        Queue<TreeNode>q=new LinkedList<>();
        q.offer(root);
        int i=1;

        while(!q.isEmpty()){
            TreeNode par=q.poll();

            if(!values[i].equals("null")){
                TreeNode left=new TreeNode(Integer.parseInt(values[i]));
                par.left=left;
                q.offer(left);
            }
            i++;

            if(!values[i].equals("null")){
                TreeNode right=new TreeNode(Integer.parseInt(values[i]));
                par.right=right;
                q.offer(right);
            }
            i++;
        }

        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));