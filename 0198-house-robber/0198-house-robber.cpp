class Solution {
public:
    int houserobbing(vector<int>& nums, int idx, vector<int>& dp){
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1){
            return dp[idx];
        }
        int take = nums[idx] + houserobbing(nums,idx+2,dp);
        int skip = houserobbing(nums,idx+1,dp);
        return dp[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
       return houserobbing(nums,0,dp);
    }
};