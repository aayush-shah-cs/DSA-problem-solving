class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int odd_sum = 0;
        int even_sum = 0;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0) even_sum += nums[i];
            else odd_sum += nums[i];
        }
        return even_sum - odd_sum;
    }
};