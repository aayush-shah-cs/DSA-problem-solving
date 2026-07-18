class Solution {
public:
    int GCD(int a,int b){
        if(b == 0) return a;
        return GCD(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        for(auto val : nums){
            mini = min(val,mini);
            maxi = max(val,maxi);
        }
        return GCD(maxi,mini);
    }
};