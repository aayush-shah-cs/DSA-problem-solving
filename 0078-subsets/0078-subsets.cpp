class Solution {
public:
    void helper(vector<int>nums,vector<vector<int>>& ans,int idx,vector<int>& temp){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        helper(nums,ans,idx+1,temp);
        temp.pop_back();
        helper(nums,ans,idx+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,ans,0,temp);

        return ans;
    }
};