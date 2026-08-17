class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Prefix sums to get subarray sums in O(1)
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // dp[i][j] = min max sum of splitting first i elements into j subarrays
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, LLONG_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                // Split point p between j-1 and i-1
                for (int p = j - 1; p < i; p++) {
                    long long currentSubarraySum = prefixSum[i] - prefixSum[p];
                    long long largestSum = max(dp[p][j - 1], currentSubarraySum);
                    dp[i][j] = min(dp[i][j], largestSum);
                }
            }
        }

        return dp[n][k];
    }
};