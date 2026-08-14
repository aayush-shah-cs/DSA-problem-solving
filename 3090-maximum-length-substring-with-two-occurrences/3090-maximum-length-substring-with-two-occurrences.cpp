class Solution {
public:
    int maximumLengthSubstring(string s) {
        int st = 0;
        int end = 0;
        unordered_map<char,int> freq;
        int ans = 0;
        while(end < s.length()){
            freq[s[end]]++;
            while(freq[s[end]] > 2){
                freq[s[st]]--;
                st++;
            }
            ans = max(ans,end-st+1);
            end++;
        }
        return ans;
    }
};