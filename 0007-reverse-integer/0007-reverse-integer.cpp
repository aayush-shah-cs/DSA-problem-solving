class Solution {
public:
    int reverse(int x) {
        int rem = 0;
        long  sum = 0;
        while(x != 0){
            rem = x % 10;
            sum = sum*10 + rem;
            x /= 10;
        }

        if(sum > INT_MAX || sum < INT_MIN) return 0;  // just range rakh diya ,i will call it as jugaad.
        return (int)sum;
    }
};