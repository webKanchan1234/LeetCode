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
    TreeNode* helper(vector<int>& inorder,vector<int>& postorder,int l,int r, unordered_map<int,int>& m,int& idx){
        if(l>r ){
            return NULL;
        }
        int val=postorder[idx--];
        TreeNode* root=new TreeNode(val);
        if(l==r){
            return root;
        }
        int inRoot=m[val];
        root->right=helper(inorder,postorder,inRoot+1,r,m,idx);
        root->left=helper(inorder,postorder,l,inRoot-1,m,idx);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>m;
        int sz=inorder.size();
        for(int i=0;i<sz;i++){
            m[inorder[i]]=i;
        }
        int idx=sz-1;
        return helper(inorder,postorder,0,sz-1,m,idx);
    }
};