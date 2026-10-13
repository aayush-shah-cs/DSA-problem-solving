class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int max_product = INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i != j && nums[i] > nums[j] && nums[i] + nums[j] == target){
                    int product = nums[i] * nums[j];
                    if(product > max_product){
                        max_product = product;
                        ans[0] = i;
                        ans[1] = j;
                    }
                }
            }
        }
        return ans;
    }
};