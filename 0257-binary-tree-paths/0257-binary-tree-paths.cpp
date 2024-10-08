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
    void help(TreeNode* root, vector<string>& ans,string s){
        if(root==NULL){
            return;
        }
        
        
        s+=to_string(root->val);
        s+="->";
        help(root->left,ans,s);
        help(root->right,ans,s);
        s.pop_back();
        s.pop_back();
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
            return;
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s;
        
        help(root,ans,s);
        return ans;
    }
};