class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // stack<int> st;
        vector<int> ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    int idx =j+1;
                    while(idx < nums2.size()) {
                        if(nums2[idx] > nums2[j]){

                            ans[i] = nums2[idx];
                            break;
                        }
                        idx++;
                    }
                    break;
                }
            }
        }
        return ans;
        
    }
};