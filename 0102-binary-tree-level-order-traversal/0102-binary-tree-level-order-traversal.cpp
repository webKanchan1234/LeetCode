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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }else{
            int lh=height(root->left);
            int rh=height(root->right);
            int mx=max(lh,rh);
            return mx+1;
        }
    }
    void levelOrder(TreeNode* root, int level,vector<int> &v){
        if(root==NULL){
            return;
        }
        if(level==1){
            v.push_back(root->val);
        }else if(level>1){
            levelOrder(root->left,level-1,v);
            levelOrder(root->right,level-1,v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        int level=height(root);
        for(int i=1;i<=level;i++){
            vector<int>v;
            levelOrder(root,i,v);
            ans.push_back(v);
        }
        return ans;
    }
};