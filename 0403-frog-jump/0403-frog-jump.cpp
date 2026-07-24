class Solution {
public:

    bool JumpOperation(int idx,int last,map<int,int>& mp,vector<int>& stones,vector<vector<int>>& dp){
        if(idx == stones.size()-1) return true;
        if(dp[idx][last] != -1) return dp[idx][last];
        bool ans = false;

        for(int i=-1;i<=1;i++){
            int jump = last + i;

            if(jump <= 0) continue;

            int nstone = stones[idx] + jump;

            if(mp.find(nstone) == mp.end()) continue;

            int idx1 = mp[nstone];

            ans = ans || JumpOperation(idx1, jump, mp, stones, dp);
        }
        return dp[idx][last] = ans;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[stones[i]] = i;
        }

       vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return JumpOperation(0,0,mp,stones,dp);
    }
};