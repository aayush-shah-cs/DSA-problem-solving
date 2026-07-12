class Solution {
public:
    int robbing(vector<int>& nums, int i, vector<int>& dp, int end){
        if(i >= end ) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + robbing(nums,i+2,dp,end);
        int skip = robbing(nums,i+1,dp,end);

        return dp[i] =  max(take,skip);
    }

    int rob(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
    
        int end = nums.size()-1;

        int case1 =  robbing(nums,0,dp1,end);
        int case2 = robbing(nums,1,dp2,end+1);

        return max(case1,case2);
    }
};