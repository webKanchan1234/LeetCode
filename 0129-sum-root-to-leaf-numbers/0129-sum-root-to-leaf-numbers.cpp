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
    int inorder(TreeNode* root, int pathSum){
        if(!root){
            return 0;
        }
        pathSum=pathSum*10+root->val;
        if(!root->left && !root->right){
            return pathSum;
        }
        int l=inorder(root->left,pathSum);
        int r=inorder(root->right,pathSum);
        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        return inorder(root,0);
    }
};