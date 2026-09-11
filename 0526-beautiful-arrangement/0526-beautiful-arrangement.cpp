class Solution {
public:
    int solve(int ele, int mask, vector<int>& place, int n) {
        if (mask == ((1 << n) - 1)) return 1;
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (place[i] % ele != 0 && ele % place[i] != 0) 
                continue;
            if ((mask & (1 << i)) != 0) 
                continue;
            int new_mask = mask | (1 << i);
            ans += solve(ele + 1, new_mask, place, n);
        }
        return ans;
    }

    int countArrangement(int n) {
        vector<int> place(n, 0);
        for (int i = 0; i < n; i++) {
            place[i] = i + 1;
        }
        int mask = 0;
        return solve(1, mask, place, n);
    }
};