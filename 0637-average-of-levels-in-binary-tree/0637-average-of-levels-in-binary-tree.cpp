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
    vector<double>ans;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    void levelSum(TreeNode* root, int level, double  &sum, int &cnt){
        if(root==NULL){
            return;
        }
        if(level==1){
            cnt++;
            sum+=root->val;
        }else if(level>1){
            levelSum(root->left,level-1,sum,cnt);
            levelSum(root->right,level-1,sum,cnt);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        int h=height(root);
        
        for(int i=1;i<=h;i++){
            double sum=0;
            int cnt=0;
            levelSum(root,i,sum,cnt);
            sum/=cnt;
            ans.push_back(sum);
        }
        return ans;
    }
};