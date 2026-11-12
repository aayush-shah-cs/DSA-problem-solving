class Solution {
public:
    void permun(int idx,vector<int>& nums,vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back({nums});
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            permun(idx+1,nums,ans);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int idx=0;
        permun(idx,nums,ans);
        return ans;
    }
};