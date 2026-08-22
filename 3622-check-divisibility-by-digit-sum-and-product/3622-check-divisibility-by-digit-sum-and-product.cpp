class Solution {
public:
    bool checkDivisibility(int n) {
        if(n < 10) return false;
        int sum = 0;
        int prod = 1;
        int m = n;
        while(m != 0){
            int rem = m%10;
            sum = sum+rem;
            prod = prod*rem;
            m /= 10;
        }
        int total = sum + prod;

        return n % total == 0;
    }
};