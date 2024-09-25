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
    int isBalance(TreeNode* root, int & mx){
        if(root==NULL){
            return 0;
        }
        int lh=isBalance(root->left,mx);
        int rh=isBalance(root->right,mx);
        mx=max(mx,abs(lh-rh));
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        int mx=0;
        isBalance(root,mx);
        if(mx>1){
            return false;
        }
        return true;
    }
};