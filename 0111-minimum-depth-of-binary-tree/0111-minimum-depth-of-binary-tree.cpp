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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        if(root->left == NULL) return minDepth(root->right) + 1;
        if(root->right == NULL) return minDepth(root->left) + 1;

        int min_left_depth = minDepth(root->left);
        int min_right_depth = minDepth(root->right);

        return min(min_left_depth, min_right_depth) + 1;
    }
};