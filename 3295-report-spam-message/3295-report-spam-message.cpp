class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> st(bannedWords.begin(),bannedWords.end());
        int count=0;
        for(auto word : message){
            if(st.count(word)) count++;
            if(count >= 2) return true;
        }
        return false;
    }
};