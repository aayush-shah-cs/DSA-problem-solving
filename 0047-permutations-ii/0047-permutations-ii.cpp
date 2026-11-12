class Solution {
public:
    void uniquePermute(int idx,vector<int>& nums,vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back({nums});
            return;
        }
        unordered_set<int> used;
        for(int i=idx;i<nums.size();i++){
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);
            swap(nums[i],nums[idx]);
            uniquePermute(idx+1,nums,ans);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        uniquePermute(0,nums,ans);
        return ans;
    }
};