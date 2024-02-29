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
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                temp.push_back(current->val);

                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

            if (level % 2 == 0) {
                for (int i = 0; i < temp.size(); i++) {
                    if (temp[i] % 2 != 1 || (i > 0 && temp[i] <= temp[i - 1])) {
                        return false;
                    }
                }
            } else {
                for (int i = 0; i < temp.size(); i++) {
                    if (temp[i] % 2 != 0 || (i > 0 && temp[i] >= temp[i - 1])) {
                        return false;
                    }
                }
            }

            level++;
        }

        return true;
    }
};