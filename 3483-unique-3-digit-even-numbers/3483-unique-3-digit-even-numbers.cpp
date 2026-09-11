class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10,0);
        for(int d : digits){
            count[d]++;
        }
        int validcount = 0;
        for(int i=100;i<=998;i+=2){
            int hun_digit = i/100;
            int tens_digit = (i/10)%10;
            int unit_digit = i%10;

            vector<int> req(10,0);
            req[hun_digit]++;
            req[tens_digit]++;
            req[unit_digit]++;

            bool possible=true;
            for(int j=0;j<10;j++){
                if(req[j]>count[j]){
                    possible=false;
                    break;
                }
            }
            if(possible){
                validcount++;
            }
        }
        return validcount;
    }
};