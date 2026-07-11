class Solution {
public:
//using memoization
    int path(int row, int col, int m, int n,vector<vector<int>>& dp){
        if(row >= m || col >= n) return 0;
        if(row == m-1 && col == n-1) return 1;

        if(dp[row][col] != -1) return dp[row][col];

        int right = path(row,col+1,m,n,dp);
        int down = path(row+1,col,m,n,dp);
        return dp[row][col] =  right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return path(0,0,m,n,dp);
    }
};