class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        vector<long> last(26, 0); // Stores count of subsequences ending with each letter
        long total = 0;

        for (char c : s) {
            int idx = c - 'a';
            long newCount = (total + 1) % mod;
            total = (total + newCount - last[idx] + mod) % mod;
            last[idx] = newCount;
        }

        return total;
    }
};