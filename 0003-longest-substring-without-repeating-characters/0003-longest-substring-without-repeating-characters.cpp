class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> freq;
        int l = 0;
        int cnt = 0;
        for(int r=0;r<s.size();r++){
            freq[s[r]]++;
            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }
            cnt = max(cnt, r-l+1);
            
        }
        return cnt;
    }
};