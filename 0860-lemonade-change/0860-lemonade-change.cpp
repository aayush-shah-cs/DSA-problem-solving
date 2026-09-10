class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // let denomination as
        int five = 0;
        int ten = 0;

        for(auto val : bills){
            if(val == 5){
                five++;
            }
            else if(val == 10){
                if(five){
                    five -= 1;
                    ten += 1;
                }
                else return false;
            }
            else{
                if(ten && five){
                    ten -= 1;
                    five -= 1;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};