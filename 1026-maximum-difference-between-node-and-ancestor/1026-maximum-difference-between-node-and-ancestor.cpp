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
    int mx=INT_MIN;
    int helper(TreeNode* root,int mi,int mx){
        if(root==NULL){
            return abs(mi-mx);
        }
        mi=min(mi,root->val);
        mx=max(mx,root->val);
        int l=helper(root->left,mi,mx);
        int r=helper(root->right,mi,mx);
        return max(l,r);
    }
    // void inorder(TreeNode* root){
    //     if(root==NULL){
    //         return;
    //     }
    //     inorder(root->left);
    //     helper(root->left,root->val);
    //     inorder(root->right);
    //     helper(root->right,root->val);
    // }
    int maxAncestorDiff(TreeNode* root) {
        
        return helper(root,root->val,root->val);
    }
};