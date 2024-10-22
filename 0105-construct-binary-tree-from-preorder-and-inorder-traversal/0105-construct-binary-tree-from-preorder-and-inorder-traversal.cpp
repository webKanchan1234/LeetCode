/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& preorder,int l,int r,vector<int>& inorder,unordered_map<int,int>& m,int& idx){
        if(l>r){
            return NULL;
        }
        int val=preorder[idx++];
        TreeNode* root=new TreeNode(val);
        if(l==r){
            return root;
        }
        int inRoot=m[val];
        root->left=helper(preorder,l,inRoot-1,inorder,m,idx);
        root->right=helper(preorder,inRoot+1,r,inorder,m,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        int sz=inorder.size();
        for(int i=0;i<sz;i++){
            m[inorder[i]]=i;
        }
        int idx=0;
        TreeNode* root=helper(preorder,0,sz-1,inorder,m,idx);
        return root;
    }
};