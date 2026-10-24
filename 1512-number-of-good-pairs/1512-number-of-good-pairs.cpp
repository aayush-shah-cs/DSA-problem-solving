class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int val : nums){
            ans += mp[val];
            mp[val]++;
        }
        return ans;
    }
};