class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0 ) return 0;
        string s = to_string(n);

        long long sum = 0;
        long long non_zero = 0;

        for(char c : s){
            if(c != '0'){
                int d = c - '0';
                non_zero = non_zero *10 + d;
                sum += d;
            }
        }
        return non_zero * sum;
    }
};