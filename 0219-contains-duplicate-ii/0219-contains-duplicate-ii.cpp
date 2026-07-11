class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mymap;

        for(int i=0;i<n;i++){
            if(mymap.find(nums[i]) != mymap.end()){
                if(i - mymap[nums[i]] <= k){
                    return true;
                }
            }
            mymap[nums[i]] = i;
        }
        return false;
    }
};