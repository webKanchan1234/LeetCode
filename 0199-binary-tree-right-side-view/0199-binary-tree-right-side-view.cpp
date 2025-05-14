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
    vector<int>ans;
    void helper(TreeNode* root, int level, int& mxlevel){
        if(root==NULL){
            return;
        }
        if(level>mxlevel){
            ans.push_back(root->val);
            mxlevel=level;
        }
        helper(root->right,level+1,mxlevel);
        helper(root->left,level+1,mxlevel);
    }
    vector<int> rightSideView(TreeNode* root) {
        int mxlevel=-1;
        helper(root,0,mxlevel);
        return ans;
    }
};