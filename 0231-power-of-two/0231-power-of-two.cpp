class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return 0;
        int val = log2(n);
        return (1 << val) == n;
    }
};