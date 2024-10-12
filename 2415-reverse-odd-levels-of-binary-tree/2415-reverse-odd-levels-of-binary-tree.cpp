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
    // vector<TreeNode*>v;
    // int height(TreeNode* root){
    //     if(root==NULL){
    //         return 0;
    //     }
    //     int lh=height(root->left);
    //     int rh=height(root->right);
    //     return max(lh,rh)+1;
    // }
    void oddLevel(TreeNode* root1,TreeNode* root2,bool level){
        if(root1==NULL || root2==NULL){
            return;
        }
        if(level){
            int t=root1->val;
            root1->val=root2->val;
            root2->val=t;
        }
        oddLevel(root1->left,root2->right,!level);
        oddLevel(root1->right,root2->left,!level);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        oddLevel(root->left,root->right,true);
        return root;
    }
};