class Solution {
public:
    int maxProduct(int n) {
       int first_max = 0;
       int sec_max = 0; 

       while(n > 0){
        int digit = n %10;
        if(digit >= first_max){
            sec_max = first_max;
            first_max = digit;
        }
        else if(sec_max < digit){
            sec_max = digit;
        }
        n /= 10;
       }
       return first_max * sec_max;
    }
};