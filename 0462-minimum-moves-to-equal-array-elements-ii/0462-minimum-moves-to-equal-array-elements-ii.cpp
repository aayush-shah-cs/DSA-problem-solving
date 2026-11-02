class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long move=0;
        int n = nums.size();
        int median = nums[n/2];

        for(int num  : nums){
            move = move + abs(num - median);
        }
        return move;
    }
};