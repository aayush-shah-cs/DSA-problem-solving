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
    int houserobbing(TreeNode* root, unordered_map<TreeNode*,int>& mp){
        if(root == NULL ) return 0;
        // if(root->left == NULL || root->right == NULL) return root->val;
        if(mp.find(root) != mp.end()){
            return mp[root];
        }

        int take = root->val;
        // int skip = 0;
        if(root->left){
         take += houserobbing(root->left->left,mp) + houserobbing(root->left->right,mp);
        }
         if(root->right) take += houserobbing(root->right->left,mp) + houserobbing(root->right->right,mp);

        int skip =  houserobbing(root->left,mp) + houserobbing(root->right,mp);
        return mp[root] = max(take,skip);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> mp;
        return houserobbing(root,mp);
    }
};