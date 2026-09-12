class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // Store interval along with original index: {l, r, weight, original_index}
        struct Interval {
            int l, r, weight, id;
        };
        
        vector<Interval> sortedIntervals(n);
        for (int i = 0; i < n; ++i) {
            sortedIntervals[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        // Sort intervals by right endpoint r
        sort(sortedIntervals.begin(), sortedIntervals.end(), [](const Interval& a, const Interval& b) {
            return a.r < b.r;
        });

        // Extract right endpoints for binary search
        vector<int> rights(n);
        for (int i = 0; i < n; ++i) {
            rights[i] = sortedIntervals[i].r;
        }

        // dp[k][i] = best state picking at most k intervals from first i intervals sorted by right endpoint
        // State representation: {weight_sum, sorted_indices_list}
        using State = pair<long long, vector<int>>;
        
        // prev[i] stores states for k - 1 picks, cur[i] for k picks
        vector<State> prev(n + 1, {0, {}});

        for (int k = 1; k <= 4; ++k) {
            vector<State> cur(n + 1, {0, {}});
            
            for (int i = 1; i <= n; ++i) {
                // Option 1: Skip current interval
                cur[i] = cur[i - 1];

                // Option 2: Take current interval
                const auto& inter = sortedIntervals[i - 1];
                
                // Find largest index j (1-based) where right endpoint < current left endpoint
                int j = lower_bound(rights.begin(), rights.end(), inter.l) - rights.begin();
                
                long long candidate_weight = prev[j].first + inter.weight;
                vector<int> candidate_indices = prev[j].second;
                candidate_indices.push_back(inter.id);
                sort(candidate_indices.begin(), candidate_indices.end());

                // Compare and keep best: higher score, or tie-break with lexicographically smaller indices
                if (candidate_weight > cur[i].first) {
                    cur[i] = {candidate_weight, candidate_indices};
                } else if (candidate_weight == cur[i].first) {
                    if (cur[i].second.empty() || candidate_indices < cur[i].second) {
                        cur[i] = {candidate_weight, candidate_indices};
                    }
                }
            }
            prev = move(cur);
        }

        return prev[n].second;
    }
};