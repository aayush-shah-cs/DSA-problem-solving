class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        int ans = 1;
        for(int num : st){
                int curr = num;
                if(st.find(curr-1) != st.end()) continue;
                int len = 1;
                while(st.find(curr + 1) != st.end()){
                    curr++;
                    len++;
                }
                ans = max(ans,len);
        }
        return ans;
    }
};