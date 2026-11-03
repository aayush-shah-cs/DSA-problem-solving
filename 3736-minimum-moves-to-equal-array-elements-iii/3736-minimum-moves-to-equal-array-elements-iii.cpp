class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int moves=0;
        for(auto val : nums){
            moves += (maxi-val);
        }
        return moves;
    }
};