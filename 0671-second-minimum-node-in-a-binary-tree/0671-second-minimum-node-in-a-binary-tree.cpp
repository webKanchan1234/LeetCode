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
    void help(TreeNode* root, int &sm, int &fm,int &unique){
        if(root==NULL){
            return;
        }
        
        if(root->val<fm){
            sm=fm;
            fm=root->val;
        }else if(root->val<sm && root->val>fm){
            sm=root->val;
        }
        if(sm==INT_MAX && root->val==INT_MAX && fm!=INT_MAX){
            unique++;
        }
        help(root->left,sm,fm,unique);
        help(root->right,sm,fm,unique);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int sm=INT_MAX;
        int fm=INT_MAX;
        int unique=0;
        help(root,sm,fm,unique);
        if(unique>0){
            return sm;
        }
        if(sm==INT_MAX){
            return -1;
        }
        return sm;
    }
};