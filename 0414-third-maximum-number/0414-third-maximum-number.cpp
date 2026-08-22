class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LONG_LONG_MIN;
        long long max2 = LONG_LONG_MIN;
        long long max3 = LONG_LONG_MIN;

        for(int val : nums){

            if(val == max1 || val == max2 || val == max3) continue;
            if(val > max1){
                max3 = max2;
                max2 = max1;
                max1 = val;
            }
            else if(val > max2 ){
                max3 = max2;
                max2 = val;
            }
            else if(val > max3) max3 = val;
        }
    // return max3 != LONG_LONG_MIN ? max3 : max1;
    if(max3 != LONG_LONG_MIN) return max3;
    return max1;
    }
};