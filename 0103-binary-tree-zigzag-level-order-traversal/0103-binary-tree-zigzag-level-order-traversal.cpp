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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>>ans;
        int flag=true;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>v(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                    q.pop();
                    int idx = flag ? i : sz-i-1;
                    v[idx]=node->val;
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
            }
            flag=!flag;
            ans.push_back(v);
            
        }
        return ans;
    }
};