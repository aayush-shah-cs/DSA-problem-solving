class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(auto ele : nums1){
            result.push_back(ele);
        }
        for(auto ele : nums2){
            result.push_back(ele);
        }

        sort(result.begin(),result.end());
        double median = 0;
        int s = result.size();
        if(s%2 == 0){
            median = result[s/2 - 1] + result[s/2];
            median = median/2;
        }
        else median = result[s/2];

        return median;
    }
};