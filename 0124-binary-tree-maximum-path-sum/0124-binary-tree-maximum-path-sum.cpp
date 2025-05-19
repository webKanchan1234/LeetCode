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
    int ans=INT_MIN;
    int maxSum(TreeNode* root){
        if (!root) return 0;

        int left = max(0, maxSum(root->left));
        int right = max(0, maxSum(root->right));

        int localMax = root->val + left + right;
        ans = max(ans, localMax);

        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return ans;
    }
};