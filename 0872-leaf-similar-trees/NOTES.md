​# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
We can solve any traversal methods such as inorder, preorder, postorder and level order traversal methods.

# Approach
<!-- Describe your approach to solving the problem. -->
Step 1. Take two vector v1 and v2 for storing the leave node for tree1 and tree 2.
Step 2. Define any traverals methods. In my case, I define preorder methods
and call it with some arguments such as root1 and v1.
Step 3. Do similar like step 2 and change v1 with v2.
Step 4. If size of v1 and is not same then return false.
Step 5. Run a for loop on any vector from 0 to v1.size() and check if value of v1 and v2 is similar or not. If value is not similar then return false. Otherwise return true. 

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(n)

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(n1+n2+max(height1,height2))

# Code
```
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
```
