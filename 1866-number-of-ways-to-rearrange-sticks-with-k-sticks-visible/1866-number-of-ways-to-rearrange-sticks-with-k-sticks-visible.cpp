#include <vector>

class Solution {
private:
    const int MOD = 1e9 + 7;

    long long solve(int n, int k, vector<vector<int>>& memo) {
        if (k == 0 || k > n) return 0;
        if (n == k) return 1;
        
        if (memo[n][k] != -1) return memo[n][k];
        long long res = (solve(n - 1, k - 1, memo) + (n - 1) * solve(n - 1, k, memo)) % MOD;
        return memo[n][k] = res;
    }

public:
    int rearrangeSticks(int n, int k) {
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
        return solve(n, k, memo);
    }
};