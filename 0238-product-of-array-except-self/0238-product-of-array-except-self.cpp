class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // vector<int> prefix(n);
        // int prod1 = 1;
        // for(int i=0;i<nums.size();i++){
        //     prefix.push_back(prod1 *= nums[i]);
        // }
        // vector<int> suffix(n);
        // int prod2 = 1;
        // for(int j=nums.size()-1;j >= 0;j--){
        //     suffix.push_back(prod2 *= nums[j]);
        // }

        // vector<int> ans(n);
        // ans[0] = suffix[1];
        // ans[nums.size()-1] = prefix[nums.size()-2];

        // for(int i=1;i<nums.size();i++){
        //     ans[i] = suffix[i+1] * prefix[i-1];
        // }
        // return ans;

        vector<int> prefix(n),suffix(n),ans(n);
        int prod = 1;
        for(int i=0;i<n;i++){
            prod *= nums[i];
            prefix[i] = prod;
        }
        prod = 1;
        for(int i=n-1;i>=0;i--){
            prod *= nums[i];
            suffix[i] = prod;
        }
        ans[0] = suffix[1];
        ans[n-1] = prefix[n-2];
        for(int i=1;i<n-1;i++){
            ans[i] = suffix[i+1]*prefix[i-1];
        }
        return ans;
    }
};