class Solution {
public:

//Recurrsion + Memoization
    int LcsDp(int i,int j,string& text1, string& text2, vector<vector<int>>& dp){

        if(i == text1.size() || j == text2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take = 0,skip = 0;

        if(text1[i] == text2[j]){
            take = 1 + LcsDp(i+1,j+1,text1,text2,dp);
        }
        else skip = max(LcsDp(i+1,j,text1,text2,dp),LcsDp(i,j+1,text1,text2,dp));

        return dp[i][j] = max(take,skip);
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        // if(text1 == text2) return text2.size();
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return LcsDp(0,0,text1,text2,dp);
    }
};