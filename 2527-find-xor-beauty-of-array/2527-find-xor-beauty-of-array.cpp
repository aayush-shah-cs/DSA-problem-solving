class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int exor = 0;
        for(auto val : nums){
            exor ^= val;
        }
        return exor;
    }
};