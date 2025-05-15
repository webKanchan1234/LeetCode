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
map<int, vector<pair<int, int>>> mp;  // col → list of (row, val)

    void dfs(TreeNode* root, int row, int col) {
        if (!root) return;

        mp[col].emplace_back(row, root->val);

        dfs(root->left, row + 1, col - 1);  // move left
        dfs(root->right, row + 1, col + 1); // move right
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);

        vector<vector<int>> res;

        for (auto& [col, nodes] : mp) {
            // Sort by row, then by value if rows are the same
            sort(nodes.begin(), nodes.end());
            vector<int> level;
            for (auto& [row, val] : nodes) {
                level.push_back(val);
            }
            res.push_back(level);
        }

        return res;
    }
};