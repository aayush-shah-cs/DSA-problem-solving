class Solution {
public:
    int GCD(int a,int b){
        if(b == 0) return a;
        return GCD(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return GCD(nums[0],nums[n-1]);
    }
};