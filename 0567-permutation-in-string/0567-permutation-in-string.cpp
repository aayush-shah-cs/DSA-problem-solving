class Solution {
public:
    bool isSameFreq(int freq1[26],int freq2[26]){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i=0;i<s1.length();i++){
            freq[s1[i] - 'a']++;
        }
        int windSize = s1.length();

        for(int i=0;i<s2.length();i++){
            int windIdx = 0;
            int idx = i;
            int freqwind[26] = {0};
            while(windIdx < windSize && idx < s2.length()){
                freqwind[s2[idx]-'a']++;
                windIdx++;
                idx++;
            }
            if(isSameFreq(freq,freqwind)){
                return true;
            }
        }
        return false;
    }
};