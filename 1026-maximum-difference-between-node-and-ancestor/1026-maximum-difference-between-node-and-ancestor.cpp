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
    void helper(TreeNode* root,int& v){
        if(root==NULL){
            return;
        }
        int d=abs(v-root->val);
        mx=max(mx,d);
        helper(root->left,v);
        helper(root->right,v);
    }
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        helper(root->left,root->val);
        inorder(root->right);
        helper(root->right,root->val);
    }
    int maxAncestorDiff(TreeNode* root) {
        inorder(root);
        return mx;
    }
};