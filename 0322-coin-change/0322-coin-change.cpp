class Solution {
public:
    int coin_pnc(vector<int>& coins, int amount,int idx,vector<vector<int>>& dp){
        
        if(amount == 0) return 0;

        if(idx == coins.size()) return 1e8;
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int take = 1e8;
        int skip = 1e8;

        if(amount >= coins[idx]){
            take = 1 + coin_pnc(coins, amount - coins[idx],idx,dp);
        }

        skip = coin_pnc(coins, amount,idx+1,dp);

        return dp[idx][amount] = min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = coin_pnc(coins, amount, 0, dp);

        if(ans == 1e8)
            return -1;

        return ans;
    }
};