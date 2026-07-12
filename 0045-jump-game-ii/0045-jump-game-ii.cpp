class Solution {
public:
    int jump(vector<int>& nums) {
        int maxidx = 0;
        int count = 0;
        int end = 0;
        
        for(int i=0;i<nums.size()-1;i++){
            maxidx = max(maxidx, i+nums[i]);
            if(i == end){
                count++;
                end = maxidx;
            }
        }
        return count;
    }
};