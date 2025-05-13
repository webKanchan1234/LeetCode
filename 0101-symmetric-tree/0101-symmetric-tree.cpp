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
    bool helper(TreeNode* root,TreeNode* root1){
       if(!root && !root1){
        return true;
       }
        if(!root || !root1){
            return false;
        }
        
        
        
        
        return (root->val==root1->val) && helper(root->left,root1->right)  && helper(root->right,root1->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return helper(root->left,root->right);
    }
};