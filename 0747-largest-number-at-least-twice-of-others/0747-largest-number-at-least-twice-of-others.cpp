class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxidx = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] > nums[maxidx]) maxidx = i;
        }
        for(int i=0;i<n;i++){
            if(i != maxidx && 2*nums[i] >nums[maxidx]) return -1;
        }
        return maxidx;
    }
};