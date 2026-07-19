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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int targetSum, vector<int>& ans_path){
        if(root == NULL) return;
        ans_path.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            if(targetSum == root->val){
                ans.push_back(ans_path);
            }
        }

        dfs(root->left,targetSum - root->val, ans_path);
        dfs(root->right, targetSum -root->val,ans_path);

        ans_path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans_path;
        dfs(root,targetSum, ans_path);
        return ans;
    }
};