class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right < nums.size()){
            freq[nums[right]]++;
            while(freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};