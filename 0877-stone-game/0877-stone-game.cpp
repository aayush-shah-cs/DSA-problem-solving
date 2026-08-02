class Solution {
public:
    int whoWins(vector<int>& piles, int i,int j, vector<vector<int>>& dp){
        if(i == j) return piles[i];
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int takeleft_side = piles[i] - whoWins(piles,i+1,j,dp);
        int takeright_side = piles[j] - whoWins(piles,i,j-1,dp);
        return dp[i][j] = max(takeleft_side, takeright_side); 
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return whoWins(piles,0,n-1,dp) > 0;
    }
};