class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        long N = n;
        if(N < 0){
            x = 1/x;
            N = -N;
        }

        double hold = myPow(x,N/2);
        if(n%2 == 0) return hold*hold;
        else return hold*hold*x;

        return hold;
    }
};