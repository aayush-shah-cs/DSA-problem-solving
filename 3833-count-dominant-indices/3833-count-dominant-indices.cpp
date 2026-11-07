class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            int sum=0;
            int count=0;
            for(int j = i + 1; j < n; j++) {
                sum += nums[j];
                count++;
            }
            double avg=(double)sum/count;
            if(nums[i]>avg) ans++;
        }
        return ans;
    }
};