
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> l(26, n), r(26, -1);
        
        // Step 1: Record first and last occurrences of each character
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            l[ch] = min(l[ch], i);
            r[ch] = max(r[ch], i);
        }
        
        // Helper function to get valid right bound for interval starting at i
        auto getRightBound = [&](int i) -> int {
            int right = r[s[i] - 'a'];
            for (int j = i; j <= right; ++j) {
                int ch = s[j] - 'a';
                if (l[ch] < i) return -1; // Overlaps with something that started earlier
                right = max(right, r[ch]);
            }
            return right;
        };

        // Step 2: Collect valid extended intervals
        vector<pair<int, int>> valid_intervals;
        for (int i = 0; i < n; ++i) {
            if (i == l[s[i] - 'a']) {
                int right = getRightBound(i);
                if (right != -1) {
                    valid_intervals.push_back({right, i}); // Store as (end, start) for sorting
                }
            }
        }
        
        // Step 3: Sort intervals by end point and select non-overlapping ones
        sort(valid_intervals.begin(), valid_intervals.end());
        
        vector<string> ans;
        int last_end = -1;
        for (const auto& [end, start] : valid_intervals) {
            if (start > last_end) {
                ans.push_back(s.substr(start, end - start + 1));
                last_end = end;
            }
        }
        
        return ans;
    }
};