class Solution {
public:
    vector<vector<int>> dp;
    int solve(int bits,int session,vector<int>& tasks,int sessionTime){
        int n = tasks.size();
        if(bits == ((1<<n)-1)) return 0;
        if(dp[bits][session] != -1)
            return dp[bits][session];
        int ans = 1e8;
        for(int i=0;i<n;i++){
            if(bits & (1 << i)) continue;
            int nbits = bits | (1 <<i);
            if(session >= tasks[i]){
                ans = min(ans,solve(nbits,session-tasks[i],tasks,sessionTime));
            }
            else{
                ans = min(ans,1+solve(nbits,sessionTime-tasks[i],tasks,sessionTime));
            }
        }
        return dp[bits][session] = ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        dp.assign(1 << n, vector<int>(sessionTime + 1, -1));
        return 1 + solve(0, sessionTime, tasks, sessionTime);
    }
};