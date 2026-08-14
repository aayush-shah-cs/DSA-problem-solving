class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max_prod = 1;
        int min_prod = INT_MAX;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                max_prod = max(max_prod,nums[i]*nums[j]);
                min_prod = min(min_prod,nums[i]*nums[j]);
            }
            ans = max(ans,(max_prod-min_prod));
        }
        return ans;
    }
};