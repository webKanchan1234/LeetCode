/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }

    void level(int lev, TreeNode* root, vector<int>& v, bool flag) {
        if (root == NULL) {
            return;
        }
        if (lev == 1) {
            v.push_back(root->val);
        }
        if (flag) {
            level(lev - 1, root->left, v,flag);
            level(lev - 1, root->right, v,flag);
        } else {
            cout<<"regre";
            level(lev - 1, root->right, v,flag);
            level(lev - 1, root->left, v,flag);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> ans;
        bool flag = true;
        for (int i = 1; i <= h; i++) {
            vector<int> v;
            level(i, root, v, flag);
            flag = !flag;
            ans.push_back(v);
        }
        return ans;
    }
};