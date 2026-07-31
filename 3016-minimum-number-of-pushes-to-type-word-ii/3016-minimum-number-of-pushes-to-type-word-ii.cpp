class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for(char c : word){
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end());
        int ans = 0;
        int idx = 0;
        for(int i=25;i>=0 && freq[i] > 0;i--){
            ans += freq[i]*(idx/8 + 1);
            idx++;
        }
        return ans;
    }
};