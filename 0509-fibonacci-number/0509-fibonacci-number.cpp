class Solution {
public:

//space Optimization , try to do that in a constant time complexity

    int fib(int n) {

        if(n == 0) return 0;
        if(n == 1) return 1;

        vector<int> dp(3);
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2;i<=n;i++){
            dp[2] = dp[0]+dp[1];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};