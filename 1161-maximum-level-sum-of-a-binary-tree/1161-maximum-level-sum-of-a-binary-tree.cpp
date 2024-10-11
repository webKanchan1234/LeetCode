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
        }
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }
    void levelSum(TreeNode* root, int level,int &sum){
        if(root==NULL){
            return;
        }
        if(level==1){
            sum+=root->val;
        }else if(level>1){
            levelSum(root->left,level-1,sum);
            levelSum(root->right,level-1,sum);
        }
    }
    int maxLevelSum(TreeNode* root) {
        int h=height(root);
        int sum=0;
        int ans=0;
        int mx=INT_MIN;
        for(int i=1;i<=h;i++){
            levelSum(root,i,sum);
            if(sum>mx){
                mx=sum;
                ans=i;
            }
            sum=0;
        }
        return ans;
    }
};