class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.length();
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                string sub1="";
                string sub2="";
                while(i < n && s1[i] != s2[i]){
                    sub1 += s1[i]; 
                    sub2 += s2[i]; 
                    i++;
                }
                ans.push_back({sub1,sub2});
            }
        }
        return ans;
    }
};