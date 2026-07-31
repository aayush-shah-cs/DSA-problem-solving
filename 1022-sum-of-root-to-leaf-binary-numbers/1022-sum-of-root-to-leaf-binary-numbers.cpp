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

    int helper_func(TreeNode* root,int curr_sum){
        if(!root) return 0;
        curr_sum = curr_sum*2 + root->val;

        if(!root->left && !root->right){
            return curr_sum;
        }

        return helper_func(root->left,curr_sum) + helper_func(root->right,curr_sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        return helper_func(root,0);
    }
};