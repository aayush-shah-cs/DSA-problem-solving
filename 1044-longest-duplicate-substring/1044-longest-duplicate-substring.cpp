class Solution {
public:
    int search(int len, string& s) {
        int n = s.length();
        long long base = 256;
        long long mod = 1e9 + 7;
        long long maxpower = 1;
        for (int i = 1; i < len; i++) {
            maxpower = (maxpower * base) % mod;
        }
        long long hash = 0;

        for (int i = 0; i < len; i++) {
            hash = (hash * base + s[i]) % mod;
        }

        unordered_map<long long, vector<int>> seenHashes;
        seenHashes[hash].push_back(0);
        for (int i = len; i < n; i++) {
            hash = (hash - (s[i - len] * maxpower) % mod + mod) % mod;
            hash = (hash * base + s[i]) % mod;

            int start = i - len + 1;
            if (seenHashes.find(hash) != seenHashes.end()) {
                for (int prev : seenHashes[hash]) {
                    if (s.substr(prev, len) == s.substr(start, len)) {
                        return start;
                    }
                }
            }
            seenHashes[hash].push_back(start);
        }
        return -1;
    }

    string longestDupSubstring(string s) {
        int n = s.length();
        int low = 1;
        int high = n - 1;
        int idx = -1;
        int maxi_len = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int st_idx = search(mid, s);
            if (st_idx != -1) {
                idx = st_idx;
                maxi_len = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if (idx == -1)
            return "";
        return s.substr(idx, maxi_len);
    }
};