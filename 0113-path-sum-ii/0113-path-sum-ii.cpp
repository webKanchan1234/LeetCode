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
    vector<vector<int>>ans;
    vector<int>v;
    void help(TreeNode* root, int targetSum){
        if(root==NULL){
            return;
        }
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(targetSum==root->val){
                ans.push_back(v);
            }
        }
        help(root->left,targetSum-root->val);
        help(root->right,targetSum-root->val);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        help(root,targetSum);
        return ans;
    }
};