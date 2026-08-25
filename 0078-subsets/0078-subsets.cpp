class Solution {
public:
    vector<vector<int>> ans;
    void findSubsets(vector<int>& nums,int idx, vector<int>& temp){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        findSubsets(nums,idx+1,temp);
        temp.pop_back();
        findSubsets(nums,idx+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        findSubsets(nums,0,temp);
        return ans;
    }
};