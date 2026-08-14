class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int max_prod = nums[n-1]*nums[n-2];
        int min_prod = nums[1]*nums[0];

        return max_prod-min_prod;
    }
};