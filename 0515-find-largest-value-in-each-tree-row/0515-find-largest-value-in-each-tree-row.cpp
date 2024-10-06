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
    // boot help(TreeNode* root, vector<int>& v){
    //     if(root==NULL){
    //         return;
    //     }

    // }
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            int mx=INT_MIN;
            for(int i=0;i<sz;i++){
                TreeNode* front=q.front();
                mx=max(mx,front->val);
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
                q.pop();
            }
            
            v.push_back(mx);
        }
        return v;
    }
};