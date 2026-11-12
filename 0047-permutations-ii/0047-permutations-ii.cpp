class Solution {
public:
vector<vector<int>> ans;
    void permun(vector<int>& nums,vector<bool>& vis,vector<int>& temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !vis[i-1]) continue;
            vis[i]=true;
            temp.push_back(nums[i]);
            permun(nums,vis,temp);
            temp.pop_back();
            vis[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<bool> vis(nums.size(),false);

        permun(nums,vis,temp);
        return ans;
    }
};