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
    
    void firstTree(TreeNode* root,vector<int>& v){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->val);
        }
        firstTree(root->left,v);
        firstTree(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;
        firstTree(root1,v1);
        firstTree(root2,v2);
        int n1=v1.size();
        int n2=v2.size();
        if(n1!=n2){
            return false;
        }
        for(int i=0;i<n1;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
};