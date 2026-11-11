class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> st(friends.begin(),friends.end());
        vector<int> ans;
        for(auto val : order){
           if(st.count(val)) ans.push_back(val);
        }
        return ans;
    }
};