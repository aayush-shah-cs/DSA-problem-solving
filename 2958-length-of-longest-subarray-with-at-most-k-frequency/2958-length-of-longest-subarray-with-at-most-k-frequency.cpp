class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int left = 0;

        int longest_subarr = 0;

        for(int right=0;right<nums.size();right++){
            freq[nums[right]]++;

                while(freq[nums[right]] > k){
                    freq[nums[left]]--;
                    left++;

                }
            
            longest_subarr = max(longest_subarr, right - left + 1);
        }
        return longest_subarr;
    }
};