class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        std::vector<int> min_len(n, INT_MAX);
        
        int left = 0, current_sum = 0;
        int ans = INT_MAX;
        int best_so_far = INT_MAX;
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            // Shrink window if sum exceeds target
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }
            
            // Found a valid subarray with sum == target
            if (current_sum == target) {
                int curr_len = right - left + 1;
                
                // If a non-overlapping valid subarray exists before 'left', calculate total length
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = std::min(ans, curr_len + min_len[left - 1]);
                }
                
                best_so_far = std::min(best_so_far, curr_len);
            }
            
            // Update DP value for index 'right'
            min_len[right] = best_so_far;
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};