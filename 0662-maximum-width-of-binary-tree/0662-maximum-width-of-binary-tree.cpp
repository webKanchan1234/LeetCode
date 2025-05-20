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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long ans=INT_MIN;

        while(!q.empty()){
            int sz=q.size();
            int mnidx=q.front().second;
            long long f=0;
            long long l=0;
            
            for(int i=0;i<sz;i++){
                auto [curr,idx]=q.front();
                q.pop();
                idx-=mnidx;
                if(i==0){
                    f=idx;
                }
                if(i==sz-1){
                    l=idx;
                }
                if(curr->left){
                    q.push({curr->left,2*idx+1});
                }
                if(curr->right){
                    q.push({curr->right,2*idx+2});
                }
            }
            ans=max(ans,l-f+1);
        }
        return ans;
    }
};